#include "painterscene.h"
#include <QDebug>

PainterScene::PainterScene(QObject *parent)
    : QGraphicsScene(parent)
    , m_toolType(tt_Line)
    , m_currentShape(nullptr)
    , m_id(-1)
{

}

PainterScene::~PainterScene(){}

void PainterScene::setToolType(int type){
    m_toolType = type;
    if(m_currentShape != nullptr){
        if(!m_currentShape->isValid()){
            delete m_currentShape;
        }
        m_currentShape = nullptr;//下次事件发生时候就可以做相应处理
    }
}

void PainterScene::onFigureAdded(const QJsonObject &figure){
    qDebug() << "PainterScene::onFigureAdded";
    Shape *item = nullptr;//生成一个即将添加的item
    QJsonObject data = figure.value("data").toObject();
    QJsonArray points = data.value("points").toArray();
    QString strType = figure.value("type").toString();

    int creatorId = figure.value("creator").toInt();
    int localId = figure.value("local_id").toInt();
    int globalId = figure.value("global_id").toInt();

    if(creatorId == m_id){
        auto it = std::find_if(m_shapes.begin(), m_shapes.end()
                               ,[=](Shape *s){
            return (s->creatorId() == creatorId && s->localId() == localId);
        });
        if(it != m_shapes.end()){
            //item已经在场景中，不需要调整
            qDebug() << "Update figure global id";
            (*it)->setGlobalId(globalId);
            return;
        }
    }
#define SET_START_AND_END_POS() \
    QPointF startPos(points[0].toInt(), points[1].toInt());\
    QPointF endPos(points[2].toInt(), points[3].toInt());\
    item->setStartPoint(startPos);\
    item->setEndPoint(endPos);

    if(strType == "line"){
        item = new SLine();
        SET_START_AND_END_POS();
    }
    else if(strType == "oval"){
        item = new SOval();
        SET_START_AND_END_POS();

    }
    else if(strType == "rectangle"){
        item = new SRectangle();
        SET_START_AND_END_POS();
    }
    else if(strType == "triangle"){
        item = new STriangle();
        SET_START_AND_END_POS();

    }
    else if(strType == "graffiti"){
        SGraffiti *graffiti= new SGraffiti();
        item = graffiti;
        QPainterPath path;
        int size = points.size();
        path.moveTo(points[0].toInt(), points[1].toInt());//移到起始点，第一个点
        for(int i = 2; i < size; i+=2){
            path.lineTo(points[i].toInt(), points[i+1].toInt());
        }
        graffiti->setPath(path);//将路径传递给graffiti
    }
    else{
        qDebug() << "Unknown figure type!";
        return;
    }

    item->setGlobalId(globalId);
    item->setLocalId(localId);
    item->setStrokeWidth(data.value("line_width").toInt());
    item->setStrokeColor(QColor::fromRgba((unsigned int)data.value("color").toDouble()));
    item->setFillColor(QColor::fromRgba((unsigned int)data.value("fill_color").toDouble()));

    addItem(item);//加入场景中
    m_shapes.push_back(item);//加入链表中
    update();
}

void PainterScene::onFigureDeleted(int id){
    auto it = std::find_if(m_shapes.begin(), m_shapes.end(),
                           [=](Shape*s){
        return s->globalId() == id;
    });
    if(it != m_shapes.end()){
        qDebug() << "PainterScene::onFigureDeleted, global id - " << id;
        removeItem(*it);
        delete *it;
        m_shapes.erase(it);
        update();
    }

}

void PainterScene::onFigureCleared(int ownerId){
    if(ownerId == -1)
    {
        qDebug() << "PainterScene::onFigureCleared, Clear All ";
        clear();
        m_shapes.clear();
        update();
    }
    else{
        auto it = m_shapes.begin();

        while(it != m_shapes.end()){
            if((*it)->creatorId() == ownerId){
                removeItem(*it);
                delete *it;
                it = m_shapes.erase(it);
                qDebug() << "PainterScene::onFigureCleared, Clear one figure of " << ownerId;
                update();//?
            }
            else{
                it++;
            }
        }
    }
}

void PainterScene::undo(){
    if(m_shapes.size()){
        Shape *item = m_shapes.back();
        emit deleteFigureReq(item->globalId());
    }
}

void PainterScene::mousePressEvent(QGraphicsSceneMouseEvent *ev){
    QGraphicsScene::mousePressEvent(ev);
    if(ev->button() != Qt::LeftButton) return;//只处理鼠标左键
    if(!ev->isAccepted()){//父类还没处理
        switch(m_toolType){
        case tt_Line:
            m_currentShape = new SLine();
            m_currentShape->setStrokeColor(Qt::black);
            m_currentShape->setStrokeWidth(2);
            break;
        case tt_Circle:
            m_currentShape = new SOval();
            m_currentShape->setStrokeWidth(0);
            m_currentShape->setFillColor(Qt::green);
            break;
        case tt_Rectangle:
            m_currentShape = new SRectangle();
            m_currentShape->setStrokeWidth(4);
            break;
        case tt_Triangle:
            m_currentShape = new STriangle();
            m_currentShape->setStrokeColor(Qt::blue);
            m_currentShape->setStrokeWidth(2);
            break;
        case tt_Graffiti:
            m_currentShape = new SGraffiti();
            m_currentShape->setStrokeColor(Qt::black);
            m_currentShape->setStrokeWidth(4);
            break;
        default:
            return;

        }
        if(m_currentShape == nullptr) return;//异常，不作处理
        addItem(m_currentShape);
        m_currentShape->setCreatorId(m_id);
        m_currentShape->setStartPoint(ev->scenePos());
    }
}

void PainterScene::mouseMoveEvent(QGraphicsSceneMouseEvent *ev){
    QGraphicsScene::mouseMoveEvent(ev);
    if(!ev->isAccepted() && m_currentShape){
        m_currentShape->setEndPoint(ev->scenePos());
        update();
    }
}

void PainterScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *ev){
    QGraphicsScene::mouseReleaseEvent(ev);
    if(ev->button() != Qt::LeftButton) return;//只处理鼠标左键
    if(!ev->isAccepted() && m_currentShape){
        if(m_currentShape->isValid()){

            m_shapes.push_back(m_currentShape);//图形保存到列表中
            QJsonObject figure;
            m_currentShape->serialize(figure);//将绘制的Json信息保存在figure中
            figure.insert("creator", QJsonValue(m_id));
            figure.insert("local_id", QJsonValue(m_currentShape->localId()));
            emit addFigureReq(figure);
        }
        else{
            removeItem(m_currentShape);
            delete m_currentShape;
        }
        m_currentShape = nullptr;
    }
}

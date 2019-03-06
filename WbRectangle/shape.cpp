#include "shape.h"


//SLine

SLine::SLine() : Shape(tt_Line), m_rcBounding(0, 0, 0, 0)
{}

void SLine::setStartPoint(const QPointF &pos){

    setPos(pos);
    m_startPosScene = pos;//保存位置值
}

void SLine::setEndPoint(const QPointF &pos){//根据end调整整个线的位置
    m_endPosScene = pos;//保存一下位置

    qreal endX = m_endPosScene.x();
    qreal endY = m_endPosScene.y();
    qreal startX = m_startPosScene.x();
    qreal startY = m_startPosScene.y();

    m_rcBounding.setWidth(qAbs(endX - startX));
    m_rcBounding.setHeight(qAbs(endY - startY));

    QPointF startPoint;//线段起点
    QPointF endPoint;//线段终点
    //scene坐标转换到本地坐标
    if(endX < startX){
        startX = endX;//startX是item左上角的位置
        startPoint.setX(m_rcBounding.width());//画线的本地坐标，起点
        endPoint.setX(0);//画线的本地坐标，终点, 因为endX < startX
    }
    else{
        startPoint.setX(0);
        endPoint.setX(m_rcBounding.width());
    }

    if(endY < startY){
        startY = endY;
        startPoint.setY(m_rcBounding.height());
        endPoint.setY(0);
    }
    else{
        startPoint.setY(0);
        endPoint.setY(m_rcBounding.height());
    }

    m_line.setPoints(startPoint, endPoint);//设置线的起点终点
    setPos(startX, startY);//设置这个item在scene中的位置, 定位的是item的左上角
}

void SLine:: setStrokeWidth(float w){
    m_strokeWidth = w;
    m_pen.setWidthF(w);
}

void SLine:: setStrokeColor(const QColor &color){
    m_strokeColor = color;
    m_pen.setColor(color);
}

QRectF SLine::boundingRect() const{
    return m_rcBounding;
}

void SLine::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->save();//保存状态
    painter->setPen(m_pen);//设置画笔
    painter->drawLine(m_line);//绘制line
    painter->restore();//恢复painter状态
}

//SRectangle

SRectangle::SRectangle(int type) : Shape(type), m_rcBounding(0, 0, 0, 0)
{}

void SRectangle::setStartPoint(const QPointF &pos){
    setPos(pos);
    m_startPosScene = pos;
}

void SRectangle::setEndPoint(const QPointF &pos){//找到左上角，定位到场景中去
    m_endPosScene = pos;

    qreal endX = m_endPosScene.x();
    qreal endY = m_endPosScene.y();
    qreal startX = m_startPosScene.x();
    qreal startY = m_startPosScene.y();

    m_rcBounding.setWidth(qAbs(endX - startX));
    m_rcBounding.setHeight(qAbs(endY - startY));

    if(endX < startX){
        startX = endX;
    }

    if(endY < startY){
        startY = endY;
    }
    setPos(startX, startY);
}


void SRectangle:: setStrokeWidth(float w){
    m_strokeWidth = w;
    m_pen.setWidthF(w);
}

void SRectangle:: setStrokeColor(const QColor &color){
    m_strokeColor = color;
    m_pen.setColor(color);
}

void SRectangle::setFillColor(const QColor &color){
    m_fillColor = color;
}

QRectF SRectangle::boundingRect() const{
    return m_rcBounding;
}

void SRectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->save();//保存状态
    //设置画笔
    if(m_strokeWidth > 0.1){
        painter->setPen(m_pen);
    }
    else{
        painter->setPen(Qt::NoPen);
    }
    //设置画刷
    if(m_fillColor == Qt::transparent){
        painter->setBrush(Qt::NoBrush);
    }
    else{
        painter->setBrush(m_fillColor);
    }
    painter->drawRect(m_rcBounding);
    painter->restore();

}


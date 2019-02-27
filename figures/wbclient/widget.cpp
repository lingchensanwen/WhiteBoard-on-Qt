#include "widget.h"
#include <QtWidgets>

int Widget::m_idBase = 0;//id_Base初始化
int Widget::GernerateId(){
    return ++m_idBase;
}

Widget::Widget(QWidget *parent) :
    QWidget(parent), new_connect(nullptr)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *namelabel = new QLabel("Input your name：");//输入名字提示
    layout->addWidget(namelabel);

    mb_namesEdit = new QLineEdit("Nana");//名字编辑框，默认Nana
    layout->addWidget(mb_namesEdit);

    auto joinBtn = new QPushButton("Join");//Join按钮
    connect(joinBtn, SIGNAL(clicked(bool)), this, SLOT(ClicktoJoin()));
    layout->addWidget(joinBtn);

    auto leftBtn = new QPushButton("Leave");//leave按钮
    connect(leftBtn, SIGNAL(clicked(bool)), this, SLOT(ClicktoLeave()));
    layout->addWidget(leftBtn);

    auto addBtn = new QPushButton("Add Figure");//Add按钮
    connect(addBtn, SIGNAL(clicked(bool)), this, SLOT(ClicktoAdd()));
    layout->addWidget(addBtn);

    m_deleteEdit = new QLineEdit;//输入删除编辑框
    m_deleteEdit->setValidator(new QIntValidator);//只允许输入整型
    layout->addWidget(m_deleteEdit);

    auto delBtn = new QPushButton("Delete Figure");//Delete按钮
    connect(delBtn, SIGNAL(clicked(bool)), this, SLOT(ClicktoDelete()));
    layout->addWidget(delBtn);

    auto ClearAllBtn = new QPushButton("Clear All");//Clear All按钮
    connect(ClearAllBtn, SIGNAL(clicked(bool)), this, SLOT(ClicktoClearAll()));
    layout->addWidget(ClearAllBtn);

    auto ClearMyselfBtn = new QPushButton("Clear Myself");//Clear Myself按钮
    connect(ClearMyselfBtn, SIGNAL(clicked(bool)), this, SLOT(ClicktoClearMyself()));
    layout->addWidget(ClearMyselfBtn);

    m_statusEdit = new QTextEdit();//显示状态编辑框
    m_statusEdit->setReadOnly(true);//设置为只读
    layout->addWidget(m_statusEdit, 1);//加上伸缩参数，拉伸时候随窗口一起变化
}

Widget::~Widget()
{

}

void Widget::ClicktoJoin(){
    if(new_connect)//判断是否有连接，若无连接，报错
    {
        return;
    }
    QString name = mb_namesEdit->text();//若有连接，取名字
    if(name.isEmpty())//名字为空时候，返回
    {
        return;
    }
    new_connect = new WbConnect(this);//若有连接，再点不处理，直接略过
    new_connect->join(name, "localhost", 1996);//与服务器建立联系
    connect(new_connect, SIGNAL(joined(QString,int)), this, SLOT(onJoined(QString, int)));
    //等待接收到join消息，joined信号发出，在界面上有所显示
    connect(new_connect, SIGNAL(someoneleft(QString,int)), this, SLOT(onLeft(QString, int)));
    //等待接收到left消息，someoneleft信号发出，在界面上有所显示
    connect(new_connect, SIGNAL(errorOccurred(QString)), this, SLOT(onError(QString)));
    //等待接收到error消息，errorOccurred信号发出，在界面上有所显示
    connect(new_connect, SIGNAL(figureAdded(QJsonObject)), this, SLOT(onFigureAdded(QJsonObject)));
    //等待接收到figureAdded消息，figureAdded信号发出，在界面上有所显示
    connect(new_connect, SIGNAL(figureDeleted(int)), this, SLOT(onFigureDeleted(int)));
    //等待接收到figureDeleted消息，figureDeleted信号发出，在界面上有所显示
    connect(new_connect, SIGNAL(figureCleared(int)), this, SLOT(onFigureClear(int)));
    //等待接收到figureClear消息，figureClear信号发出，在界面上有所显示



}

void Widget::ClicktoLeave(){
    if(!new_connect){
        return;
    }
    new_connect->left();//离开时，发送离开信息到服务器
}

void Widget::ClicktoAdd(){
    QJsonObject *root = new QJsonObject();
    root->insert("type", QJsonValue("line"));
    root->insert("creator", QJsonValue(new_connect->id()));
    root->insert("local_id", QJsonValue(GernerateId()));

    QJsonObject data;
    data.insert("color", QJsonValue(1234));
    data.insert("fill_color", QJsonValue(12345));
    data.insert("line_width", QJsonValue(3));

    QJsonArray points;
    points.append(QJsonValue(50));
    points.append(QJsonValue(150));
    points.append(QJsonValue(250));
    points.append(QJsonValue(350));

    data.insert("points", QJsonArray(points));
    root->insert("data", QJsonValue(data));

    m_figures.push_back(root);
    new_connect->AddFigure(*root);
}

void Widget::ClicktoDelete(){
    if(new_connect){
        QString strID = m_deleteEdit->text();
        if(strID.isEmpty()) return ;
        new_connect->DeleteFigure(strID.toInt());
    }
}

void Widget::ClicktoClearAll(){
    if(new_connect) new_connect->ClearFigures(-1);
}

void Widget::ClicktoClearMyself(){
    if(new_connect) new_connect->ClearFigures(new_connect->id());
}

void Widget::onJoined(QString name, int id){
    m_statusEdit->append(QString("%1 (%2) Joined\n").arg(name).arg(id));
}

void Widget::onLeft(QString name, int id){
    if(!new_connect){
        return;
    }
    if(id == new_connect->id())//自己离开
    {
        m_statusEdit->append("You have chosen to leave\n");
        new_connect->deleteLater();//删掉自己
        new_connect= nullptr;
    }
    else
    {
        m_statusEdit->append(QString("%1 (%2) Left\n").arg(name).arg(id));
    }

}

void Widget::onFigureAdded(const QJsonObject &figure){
    int myId = new_connect->id();
    int creatorId = figure.value("creator").toInt();
    if(myId != creatorId){
        m_figures.push_back(new QJsonObject(figure));
        m_statusEdit->append(QString("Add Figure, global id - %1, local id - %2 creator - %3")
                             .arg(figure.value("global_id").toInt())
                             .arg(figure.value("local_id").toInt())
                             .arg(figure.value("creator").toInt()));
    }
    else{
        int local_id = figure.value("local_id").toInt();
        int global_id = figure.value("global_id").toInt();
        auto it = std::find_if(m_figures.begin(), m_figures.end(), [=](QJsonObject* f){
           return (local_id == f->value("local_id").toInt());
        });
        if(it != m_figures.end()){
            (*it)->insert("global_id", QJsonValue("global_id").toInt());
            m_statusEdit->append(QString("Updated figure global id - %1 local id -%2").arg(global_id).arg(local_id));
        }
    }
}

void Widget::onFigureDeleted(int global_id){
    m_figures.remove_if([=](QJsonObject* f){
        if(global_id == f->value("global_id").toInt()){
            this->m_statusEdit->append(QString("Deleted figure - %1").arg(global_id));
            delete f;
            return true;
        }
        return false;
    });
}

void Widget::onFigureClear(int owner_id){
    if(owner_id == -1){
        if(m_figures.size()){
            for(auto f: m_figures) delete f;
            m_figures.clear();
        }
        m_statusEdit->append("Clear All Figures!");
    }
    else{
        m_figures.remove_if([=](QJsonObject* f){
            if(owner_id == f->value("owner_id").toInt())
            {
                this->m_statusEdit->append(QString("Delete figure %1 of user %2")
                                           .arg(f->value("global_id").toInt())
                                           .arg(owner_id));
                delete f;
                return true;
            }
            return false;
        });
    }
}

void Widget::onError(const QString &desc){
    m_statusEdit->append(desc);
    if(new_connect){
        m_statusEdit->append("release WBConnection");
        new_connect->deleteLater();
        new_connect = 0;
    }
}

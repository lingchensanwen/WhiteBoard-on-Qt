#include "widget.h"
#include <QtWidgets>

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
    connect(new_connect, SIGNAL(joined(QString,int)), this, SLOT(onJoined(QString, int)));
    connect(new_connect, SIGNAL(someoneleft(QString,int)), this, SLOT(onLeft(QString, int)));

    new_connect->join(name, "localhost", 1996);

}

void Widget::ClicktoLeave(){
    if(!new_connect){
        return;
    }
    new_connect->left();
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

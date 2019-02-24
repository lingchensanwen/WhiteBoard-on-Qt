#include "widget.h"
#include <QHBoxLayout> //水平布局
#include <QVBoxLayout> //垂直布局
#include <QPushButton>
#include <QLabel>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent), new_connect(nullptr)
{
    QHBoxLayout *mainlayout = new QHBoxLayout(this);//主界面设为左右分割
    QVBoxLayout *leftlayout = new QVBoxLayout;//设置左页面为垂直布局
    mainlayout->addLayout(leftlayout);//将左页面加入主页面

    QLabel *sendMsg = new QLabel("Send Message:");//要发送标签，作为提示
    leftlayout->addWidget(sendMsg);

    ToSendMsg = new QLineEdit;
    leftlayout->addWidget(ToSendMsg);

    QPushButton *SendButton = new QPushButton("Send");//构建一个按钮
    leftlayout->addWidget(SendButton);
    connect(SendButton, SIGNAL(clicked(bool)), this, SLOT(SendMsgToServer()));//点击时触发信号

    leftlayout->addStretch(1);//布局时拉伸不变？

    QVBoxLayout *rightlayout = new QVBoxLayout;//建立右页面为垂直布局
    mainlayout->addLayout(rightlayout);//将右页面加入主页面
    QLabel *recvMsg = new QLabel("Recive Message:");//要接收标签，作为提示
    rightlayout->addWidget(recvMsg);

    ToRecMsg = new QLineEdit;
    ToRecMsg->setReadOnly(true);//只用来显示，设置为只读
    rightlayout->addWidget(ToRecMsg);

    rightlayout->addStretch(1);
}

Widget::~Widget()
{
}

void Widget::Interface(QString host, quint16 port)
{
    if(!new_connect)
    {
    new_connect = new WbConnect(this);
    connect(new_connect, SIGNAL(connected()), this, SLOT(SetConnect()));//连接上的时候，我们希望知道
    connect(new_connect, SIGNAL(message(QByteArray)), this, SLOT(RecMsgFromServer(QByteArray)));//收到消息时，希望得到通知
    new_connect->connectToHost(host, port);
    }
}

void Widget::SetConnect()
{
    qDebug() << __FUNCTION__;//连接上时，打印出函数信息
}

void Widget::SendMsgToServer(){
    if(new_connect && new_connect->state() == QAbstractSocket::ConnectedState){
        QString msg = ToSendMsg->text();
        if(msg.length()){
            new_connect->write(msg.toUtf8());
        }
    }

}
void Widget::RecMsgFromServer(QByteArray data)
{
    QString strMsg = QString::fromUtf8(data);//接收到消息后显示消息，消息用UTF8发送的
    ToRecMsg->setText(strMsg);
}

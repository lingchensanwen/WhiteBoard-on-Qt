#include "connectclient.h"
#include <QHostAddress>
#include <qdebug.h>

ConnectClient::ConnectClient(QObject *parent):QTcpSocket(parent)//列表赋值，指定父窗口
{
    connect(this, SIGNAL(readyRead()), this, SLOT(ToRead()));//连接信号和槽，readyRead从QLDevice继承得来
    connect(this, SIGNAL(disconnected()), this, SLOT(deleteLater()));//断开时候
}
ConnectClient::~ConnectClient(){
    qDebug() << __FUNCTION__ << "Connect Over"; //退出时打印函数名字
}

QString ConnectClient::info()//打印信息
{
    QString strInfo = QString("%1 : %2").arg(peerAddress().toString()).arg(peerPort());
    return strInfo;

}

void ConnectClient::ToRead()
{
    QByteArray data = readAll();
    data.append('\n');//json换行来界定包边界
    write(data);
}

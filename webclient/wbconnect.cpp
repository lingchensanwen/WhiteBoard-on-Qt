#include "wbconnect.h"
#include <QDebug>
WbConnect::WbConnect(QObject *parent): QTcpSocket(parent)
{
    connect(this, SIGNAL(connected()), this, SLOT(InConnect()));
    connect(this, SIGNAL(readyRead()), this, SLOT(ToRead()));
    connect(this, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(Error(QAbstractSocket::SocketError)));

}

WbConnect::~WbConnect()
{}

void WbConnect::InConnect(){
    qDebug() << __FUNCTION__;
}


void WbConnect::ToRead(){

    while(canReadLine()){
        QByteArray data = readLine();//一次读取一行
        data.chop(1);//去掉换行符
        emit message(data);
    }
}

void WbConnect::Error(QAbstractSocket::SocketError err){

    qDebug() << "Some Error happened" <<errorString();
}

#include "wbconnect.h"
#include <QDebug>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>

WbConnect::WbConnect(QObject *parent): QTcpSocket(parent)
{
    connect(this, SIGNAL(connected()), this, SLOT(InConnect()));
    connect(this, SIGNAL(readyRead()), this, SLOT(ToRead()));
    connect(this, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(Error(QAbstractSocket::SocketError)));

}

WbConnect::~WbConnect()
{}

void WbConnect::join(QString name, QString host, int port){
    mb_names = name;
    connectToHost(host, port);
}

void WbConnect::left(){
    const char leftMsg[] = "{\"type\":\"left\"}\n";//离开时发送该消息给服务端
    write(leftMsg);
}

void WbConnect::InConnect(){//join时候发送join信息给服务端
    qDebug() << __FUNCTION__;
    QJsonDocument doc;
    QJsonObject root;
    root.insert("type", QJsonValue("join"));
    root.insert("name", QJsonValue(mb_names));
    doc.setObject(root);
    QByteArray joinMsg = doc.toJson(QJsonDocument::Compact);
    joinMsg.append('\n');
    write(joinMsg);
}


void WbConnect::ToRead(){

    while(canReadLine()){
        QByteArray data = readLine();//一次读取一行
        data.chop(1);//去掉换行符

        QJsonParseError error;
        QJsonDocument doc = QJsonDocument::fromJson(data, &error);
        if(error.error == QJsonParseError::NoError )//判断是否出错
        {
            QJsonObject root = doc.object();
            QString type = root.value("type").toString();
            if(type == "join_reply"){
                mb_ids = root.value("id").toInt();
                //TODO: extra figures and update
                emit joined(mb_names, mb_ids);
            }
            else if(type == "someone_joined"){
                QString name = root.value("name").toString();
                int id = root["id"].toInt();
                emit joined(name, id);
            }
            else if(type == "user_left")
            {
                QString name = root.value("name").toString();
                int id = root["id"].toInt();
                emit someoneleft(name, id);
            }
            else{
            qDebug() << "WbConnect::ToRead, unknown message, type -" << type;
            }
        }
    }
}

void WbConnect::Error(QAbstractSocket::SocketError err){

    qDebug() << "Some Error happened" <<errorString();
}

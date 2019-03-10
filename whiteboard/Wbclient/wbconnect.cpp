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
    const char leftMsg[] = "{\"type\":\"left\"}\n";//离开时调用write方法，发送该消息给服务端
    write(leftMsg);

}

void WbConnect::AddFigure(const QJsonObject &figure){//add时候调用write方法，发送add信息给服务器
    QJsonDocument doc;
    QJsonObject root;
    root.insert("type", QJsonValue("add"));
    root.insert("figure", QJsonValue(figure));
    doc.setObject(root);
    QByteArray json = doc.toJson(QJsonDocument::Compact);
    json.append("\n");
    write(json);
    flush();
}

void WbConnect::DeleteFigure(int id){//delete时候调用write方法，发送delete信息给服务器
    QString msg = QString("{\"type\":\"delete\",\"global_id\":%1}\n").arg(id);
    QByteArray Msg = msg.toUtf8();
    write(Msg);
    flush();
}

void WbConnect::ClearFigures(int ownerId){//clear时候调用write方法，发送clear信息给服务器
    QString msg = QString("{\"type\":\"clear\",\"owner_id\":%1}\n").arg(ownerId);
    QByteArray Msg = msg.toUtf8();
    write(Msg);
    flush();
}


void WbConnect::InConnect(){//join时候调用write方法，发送join信息给服务端
    qDebug() << __FUNCTION__;
    QJsonDocument doc;
    QJsonObject root;
    root.insert("type", QJsonValue("join"));
    root.insert("name", QJsonValue(mb_names));
    doc.setObject(root);
    QByteArray joinMsg = doc.toJson(QJsonDocument::Compact);
    joinMsg.append('\n');
    write(joinMsg);
    flush();
}


void WbConnect::ToRead(){//处理来自服务端消息

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
                emit joined(mb_names, mb_ids);
                //extract figures and update
                QJsonArray figures = root.value("figures").toArray();
                for(auto it = figures.begin(); it != figures.end(); it++)
                {
                    emit figureAdded((*it).toObject());
                }


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
            else if(type == "add"){
                emit figureAdded(root.value("figure").toObject());
            }
            else if(type == "delete"){
                emit figureDeleted(root.value("global_id").toInt());
            }
            else if(type == "clear"){
                emit figureCleared(root.value("owner_id").toInt());
            }
            else if(type == "chat"){
                QString name = root["name"].toString();
                mb_name = name.toUtf8();//转换为UTF8格式
                QString message = root["message"].toString();
                msg = message.toUtf8();
                emit UserChated(mb_name, msg);//发射信号
            }

            else{
            qDebug() << "WbConnect::ToRead, unknown message, type -" << type;
            }
        }
    }
}

void WbConnect::Error(QAbstractSocket::SocketError err){

    qDebug() << "Some Error happened" <<errorString();
    emit errorOccurred(errorString());
}

#include "connectclient.h"
#include <QHostAddress>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <qdebug.h>

int ConnectClient::m_idBase = 0;

int ConnectClient::GenerateNewId(){
    return ++m_idBase;//简单的id产生，自增
}

int ConnectClient::m_figureIdBase = 0;
int ConnectClient::GenerateNewFigureId(){
    return ++m_figureIdBase;
}
ConnectClient::ConnectClient(QObject *parent):QTcpSocket(parent), mb_id(-1)//列表赋值，指定父窗口
{
    connect(this, SIGNAL(readyRead()), this, SLOT(ToRead()));//连接信号和槽，readyRead从QLDevice继承得来
    connect(this, SIGNAL(disconnected()), this, SLOT(deleteLater()));//断开时候
}
ConnectClient::~ConnectClient(){
    if(mb_id > 0){
        emit UserLeft(mb_name, mb_id);
        //析构时候id依然存在，可能是对方直接关了连接，发送消息告知其他人他离开
    }
    qDebug() << __FUNCTION__ << "Connect Over"; //退出时打印函数名字

}

QString ConnectClient::info()//打印信息
{
    QString strInfo = QString("%1 : %2").arg(peerAddress().toString()).arg(peerPort());//if connected, who are we connecting to
    return strInfo;

}

void ConnectClient::ToRead()
{
    while(canReadLine()){
        QByteArray data = readLine();
        data.chop(1);
        qDebug() << "message: " <<data.data();
        QJsonParseError error;
        QJsonDocument doc = QJsonDocument::fromJson(data, &error);//数据和error都传进来
        if(error.error == QJsonParseError::NoError){//如果没错
            QJsonObject root = doc.object();
            QString type = root.value("type").toString();
            if(type == "join"){
                if(mb_id < 0)//用户未登陆过
                {
                    mb_id = GenerateNewId();
                    QString name = root["name"].toString();
                    mb_name = name.toUtf8();//转换为UTF8格式
                    qDebug() << mb_name << "join, id - " << mb_id << "from" <<info();
                    emit UserJoin(mb_name, mb_id);//发射信号，有一个人已经登陆成功
                }
            }
            else if(type == "left"){
                if(mb_id > 0)//判断用户是否在聊天室中
                {
                    qDebug() << mb_name << "left, id - "<< mb_id << "from" << info();
                    emit UserLeft(mb_name, mb_id);
                }
            }
            else if(type == "add"){
                QJsonObject figure = root.value("figure").toObject();
                figure.insert("global_id", QJsonValue(GenerateNewFigureId()));
                emit addFigureReq(figure);
            }
            else if(type == "delete"){
                emit deleteFigureReq(root.value("global_id").toInt());
            }
            else if(type == "clear"){
                emit clearFigureReq(root.value("owner_id").toInt());
            }
            else if(type == "chat"){
                QString name = root["name"].toString();
                mb_name = name.toUtf8();//转换为UTF8格式
                QString message = root["message"].toString();
                msg = message.toUtf8();//转换为UTF8格式

                qDebug() << mb_name << "talked, message - " << msg;
                qDebug() << "Ready to emit" ;
                emit UserChat(mb_name, msg);//发射信号
            }

            else{
                qDebug() << __FUNCTION__ << "got unknown message, type -" <<type;
            }

        }
        else{
            qDebug() << "ConnectClient::ToRead(), json error -" << error.error;
        }
    }
}

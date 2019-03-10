#include "wbserver.h"
#include <algorithm>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QDebug>

WbServer::WbServer(QObject *parent): QTcpServer(parent){}

WbServer::~WbServer(){}

void WbServer::incomingConnection(qintptr sock){
    ConnectClient *thread_now = new ConnectClient(this);
    thread_now->setSocketDescriptor(sock);//设置描述符
    mb_clients.push_back(thread_now);//连接加入列表中
    connect(thread_now, SIGNAL(UserJoin(QByteArray,int)), this, SLOT(onUserJoined(QByteArray,int)));
    connect(thread_now, SIGNAL(UserLeft(QByteArray,int)), this, SLOT(onUserLeft(QByteArray,int)));
    connect(thread_now, SIGNAL(addFigureReq(QJsonObject)), this, SLOT(onAddFigureReq(QJsonObject)));
    connect(thread_now, SIGNAL(deleteFigureReq(int)), this, SLOT(onDeleteFigureReq(int)));
    connect(thread_now, SIGNAL(clearFigureReq(int)), this, SLOT(onClearFigureReq(int)));
    connect(thread_now, SIGNAL(UserChat(QByteArray,QByteArray)), this, SLOT(onUserChat(QByteArray,QByteArray)));
    qDebug() << __FUNCTION__ << " : " << thread_now->info(); //打印调试信息，打印客户端info
}

void WbServer::onUserJoined(QByteArray name, int id){
        //查找用户对应连接是否维护起来，若是再进行处理
    auto it = std::find_if(mb_clients.begin(), mb_clients.end(),//lambda 表达式以传值的形式捕获同范围内的变量
            [=](ConnectClient*& thread_now){                   //mb_clients中查找thread_now
        return id == thread_now->id();
    });
    if(it != mb_clients.end()){
        //返回一些消息给加入端
        QJsonDocument doc;
        QJsonObject root;

        root.insert("type", QJsonValue("join_reply"));
        root.insert("id", QJsonValue(id));

        //历史图源
        if(m_figures.size() > 0){
            root.insert("figures", QJsonValue(m_figures));
        }
        doc.setObject(root);
        QByteArray jsonString = doc.toJson(QJsonDocument::Compact);
        jsonString.append("\n");//加入换行作为边界
        (*it)->write(jsonString);//调用write方法，将消息返回给加入的客户端

        //广播通知其他客户端
        QJsonDocument broadcast_doc;
        QJsonObject broadcast_root;

        broadcast_root.insert("type", QJsonValue("someone_joined"));
        broadcast_root.insert("id", QJsonValue(id));
        QString joinedName = QString::fromUtf8(name);
        broadcast_root.insert("name", QJsonValue(joinedName));
        broadcast_doc.setObject(broadcast_root);
        QByteArray joinedMsg = broadcast_doc.toJson(QJsonDocument::Compact);
        joinedMsg.append("\n");
        for(auto all_connect : mb_clients){
            if(all_connect->id() != id){
                all_connect->write(joinedMsg);
            }
        }

    }

}

void WbServer::onUserLeft(QByteArray name, int id){
    //解析消息，给离开的人返回状态
    QJsonDocument doc;
    QJsonObject root;
    root.insert("type", QJsonValue("user_left"));
    root.insert("id", QJsonValue(id));
    QString LeftName = QString::fromUtf8(name);
    root.insert("name", QJsonValue(LeftName));
    doc.setObject(root);
    QByteArray jsonString = doc.toJson(QJsonDocument::Compact);
    jsonString.append("\n");

    bool removed = false;
    mb_clients.remove_if([=, &removed](ConnectClient*& thread_now){//removed 通过引用被捕获，其他变量通过值被捕获
        if(id == thread_now->id()){
            removed = true;
            thread_now->write(jsonString);
            thread_now->resetState();
            return true;//返回true，对应thread_now连接被清除
        }
        return false;
    });
    if(!removed) return;//removed不正常，不再处理
    //广播有人离开
    qDebug() << "WbServer::onUserLeft broadcast someone left";
    for(auto all_connect: mb_clients) all_connect->write(jsonString);
}

void WbServer::onAddFigureReq(const QJsonObject &figure){
    //创建要广播的消息
    m_figures.append(QJsonValue(figure));
    QJsonDocument doc;
    QJsonObject root;
    root.insert("type", QJsonValue("add"));
    root.insert("figure", QJsonValue(figure));
    doc.setObject(root);
    QByteArray msg = doc.toJson(QJsonDocument::Compact);
    msg.append("\n");
    //服务端广播add消息
    for(auto c: mb_clients) c->write(msg);
}

void WbServer::onDeleteFigureReq(int globalId){
    //用globalId匹配，在列表中若找到，即删除
    auto it = m_figures.begin();
    while(it != m_figures.end()){
        if(globalId == it->toObject().value("global_id").toInt())
        {
            qDebug() << __FUNCTION__ << "delete a figure";
            m_figures.erase(it);
            break;
        }
        it++;
    }
    //广播
    char msg[128] = {0};
    int sz = sprintf(msg, "{\"type\":\"delete\",\"global_id\":%d}\n", globalId);//sz为这串信息的大小
    for(auto c : mb_clients) c->write(msg, sz);//write sz个大小的数据（msg）
}

void WbServer::onClearFigureReq(int ownerId){
    //ownerId=1时候，清除所有
    if(ownerId == -1){
        while(m_figures.size()) m_figures.pop_front();
    }
    else{
        auto it = m_figures.begin();
        while(it != m_figures.end()){
            if(ownerId == it->toObject().value("creator").toInt()){
                it = m_figures.erase(it);
                qDebug() << __FUNCTION__ << " delete a figure of " << ownerId;
            }
            it++;
        }
    }
    //广播
    char msg[128] = {0};
    int sz = sprintf(msg, "{\"type\":\"clear\",\"owner_id\":%d}\n", ownerId);//sz为这串信息的大小
    for(auto c : mb_clients) c->write(msg, sz);//write sz个大小的数据（msg）

}

void WbServer::onUserChat(QByteArray mb_name, QByteArray msg){
    QJsonDocument doc;
    QJsonObject root;
    root.insert("type", QJsonValue("chat"));
    QString Name = QString::fromUtf8(mb_name);
    root.insert("name", QJsonValue(Name));
    QString Msg = QString::fromUtf8(msg);
    root.insert("message", QJsonValue(Msg));
    doc.setObject(root);
    QByteArray json = doc.toJson(QJsonDocument::Compact);
    json.append("\n");
    for(auto c : mb_clients) c->write(json);
}

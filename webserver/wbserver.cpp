#include "wbserver.h"

WbServer::WbServer(QObject *parent): QTcpServer(parent){}

WbServer::~WbServer(){}

void WbServer::incomingConnection(qintptr sock){
    ConnectClient *thread_now = new ConnectClient(this);
    thread_now->setSocketDescriptor(sock);//设置描述符
    mb_clients.push_back(thread_now);//连接加入列表中
    qDebug() << __FUNCTION__ << " : " << thread_now->info(); //打印调试信息，打印客户端info
}

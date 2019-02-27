#ifndef WBSERVER_H
#define WBSERVER_H

#include <QTcpServer>
#include <list>
#include "connectclient.h"
class WbServer: public QTcpServer
{
    Q_OBJECT
public:
    WbServer(QObject *parent = 0);
    ~WbServer();

protected:
    void incomingConnection(qintptr sock);//接收传入连接

protected:
    std::list<ConnectClient*> mb_clients;//list保存每个客户端连接
};


#endif // WBSERVER_H

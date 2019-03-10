#ifndef WBSERVER_H
#define WBSERVER_H

#include <QTcpServer>
#include <list>
#include "connectclient.h"
#include <QJsonArray>

class WbServer: public QTcpServer
{
    Q_OBJECT
public:
    WbServer(QObject *parent = 0);
    ~WbServer();
protected slots:
    void onUserJoined(QByteArray name, int id);
    void onUserLeft(QByteArray name, int id);
    void onAddFigureReq(const QJsonObject &figure);
    void onDeleteFigureReq(int globalId);
    void onClearFigureReq(int ownerId);
    void onUserChat(QByteArray mb_name,QByteArray msg);

protected:
    void incomingConnection(qintptr sock);//接收传入连接

protected:
    std::list<ConnectClient*> mb_clients;//list保存每个客户端连接
    QJsonArray m_figures;//保存所有的图表

};




#endif // WBSERVER_H

#ifndef WBCONNECT_H
#define WBCONNECT_H

#include <QTcpSocket>

class WbConnect: public QTcpSocket//继承
{
    Q_OBJECT
public:
    WbConnect(QObject* parent = 0);//父窗口为当前窗口，程序开始时启动
    ~WbConnect();

signals:
    void message(QByteArray data);//将消息传出来


protected slots:
    void InConnect();//连接上时，槽
    void ToRead();//读取，槽
    void Error(QAbstractSocket::SocketError err);//出现错误，槽
};


#endif // WBCONNECT_H

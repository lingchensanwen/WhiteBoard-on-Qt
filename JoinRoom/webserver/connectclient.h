#ifndef CONNECTCLIENT_H
#define CONNECTCLIENT_H

#include <QTcpSocket>

class ConnectClient : public QTcpSocket //继承
{
    Q_OBJECT //使用QT必要的
public:
    ConnectClient(QObject *parent = 0);//父窗口为当前窗口，程序开始时启动
    ~ConnectClient();

    QString info();//信息

protected slots://声明槽，子类中也可调用
    void ToRead();

};
#endif // CONNECTCLIENT_H

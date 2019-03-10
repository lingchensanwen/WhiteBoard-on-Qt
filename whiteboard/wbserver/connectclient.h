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

    int id(){return mb_id;}//每一个客户端连接都有一个id
    void resetState(){ mb_id = -1;}//用户断开时候，id重置为-1

    static int GenerateNewId();
    static int GenerateNewFigureId();

signals:
    void UserJoin(QByteArray name, int id);
    void UserLeft(QByteArray name, int id);
    void UserChat(QByteArray mb_name,QByteArray msg);
    void addFigureReq(const QJsonObject &figure);
    void deleteFigureReq(int global_id);
    void clearFigureReq(int owner_id);

protected slots://声明槽，子类中也可调用
    void ToRead();

protected:
    static int m_idBase;//全局唯一的id，辅助产生用户id
    static int m_figureIdBase;
    QByteArray mb_name; //名字
    QByteArray msg;
    int mb_id;

};
#endif // CONNECTCLIENT_H

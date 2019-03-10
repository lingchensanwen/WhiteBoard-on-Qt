#ifndef WBCONNECT_H
#define WBCONNECT_H

#include <QTcpSocket>

class WbConnect: public QTcpSocket//继承
{
    Q_OBJECT
public:
    WbConnect(QObject* parent = 0);//父窗口为当前窗口，程序开始时启动
    ~WbConnect();

    void join(QString name, QString host, int port);
    void left();

    int id(){ return mb_ids; }

    void AddFigure(const QJsonObject &figure);//希望拿到Json表示的图表
    void DeleteFigure(int id);//delete global id
    void ClearFigures(int OwnerId);//若为-1清除所有，否则为某人画的

signals:
    void message(QByteArray data);//将消息传出来
    void joined(QString name, int id);
    void someoneleft(QString name, int id);
    void figureAdded(const QJsonObject &figure);
    void figureDeleted(int id);
    void figureCleared(int OwnerId);
    void errorOccurred(const QString & desc);
    void UserChated(QString mb_name,QString msg);

protected slots:
    void InConnect();//连接上时，槽
    void ToRead();//读取，槽
    void Error(QAbstractSocket::SocketError err);//出现错误，槽

protected:
    QString mb_names;
    int mb_ids;
    QByteArray mb_name; //名字
    QByteArray msg;
};


#endif // WBCONNECT_H

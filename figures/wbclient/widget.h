#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "wbconnect.h"
#include <QLineEdit>
#include <QTextEdit>


class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    static int GernerateId();

protected slots:
    void ClicktoJoin();//界面加入按钮
    void ClicktoLeave();//界面离开按钮
    void ClicktoAdd();
    void ClicktoDelete();
    void ClicktoClearAll();
    void ClicktoClearMyself();

    //响应界面，处理wbconnect定义的那些信号
    void onJoined(QString name, int id);
    void onLeft(QString name, int id);
    void onFigureAdded(const QJsonObject &figure);
    void onFigureDeleted(int global_id);
    void onFigureClear(int owner_id);
    void onError(const QString &desc);

protected:
    WbConnect *new_connect;
    QLineEdit *mb_namesEdit;
    QTextEdit *m_statusEdit;
    QLineEdit *m_deleteEdit;
    std::list<QJsonObject*> m_figures;//缓存所有figure对应的图表
    static int m_idBase;
};

#endif // WIDGET_H

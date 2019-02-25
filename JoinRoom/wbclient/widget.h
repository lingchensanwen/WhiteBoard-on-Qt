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

protected slots:
    void ClicktoJoin();//界面加入按钮
    void ClicktoLeave();//界面离开按钮
    void onJoined(QString name, int id);
    void onLeft(QString name, int id);

protected:
    WbConnect *new_connect;
    QLineEdit *mb_namesEdit;
    QTextEdit *m_statusEdit;
};

#endif // WIDGET_H

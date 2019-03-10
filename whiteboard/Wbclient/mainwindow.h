#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "painterscene.h"
#include "wbconnect.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected slots:
    void onDrawLineAct();
    void onDrawRectangleAct();
    void onDrawCircleAct();
    void onDrawTriangleAct();
    void onDrawFreeAct();
    void onUndo();
    void onClearAll();

    void onJoinButtonClicked();

    //和服务端交互
    void onJoined(QString name, int id);
    void onSomeoneleft(QString name, int id);
    void onFigureAdded(const QJsonObject &figure);
    void onFigureDeleted(int id);
    void onFigureCleared(int OwnerId);
    void onErrorOccurred(const QString & desc);

    //响应painterscene，完成一个图形的绘制时添加给服务端
    void onAddFigureReq(const QJsonObject &figure);
    //响应菜单，工具条上按钮
    void onDeleteFigureReq(int id);
    void onClearFigureReq(int ownerId);
    void onUserChated(QString mb_name,QString msg);


protected:
    void prepareJoinUI();
    void preparePainterUI();

protected:
    PainterScene *m_scene;
    WbConnect *m_conn;
    QString name_saver;
    QLineEdit *m_nameEdit;
    QLineEdit *m_hostEdit;
    QTextEdit *m_statusEdit;
    QToolBar *m_toolBar;//切换界面保存toolBar
    QLineEdit *send_message;

protected slots:
    void ClicktoSend();
};

#endif // MAINWINDOW_H

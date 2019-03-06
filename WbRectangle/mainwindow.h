#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "painterscene.h"

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

protected:
    PainterScene *m_scene;
};

#endif // MAINWINDOW_H

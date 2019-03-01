#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

};

#endif // MAINWINDOW_H

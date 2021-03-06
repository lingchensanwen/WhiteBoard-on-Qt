#include "mainwindow.h"
#include <QtWidgets>
#include "checkbox.h"
#include "painterscene.h"
#include "painterview.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QToolBar *toolbar = addToolBar("Figure Type");
    QActionGroup *actionGroup = new QActionGroup(toolbar);//加到一个组中，可以设定选择或者互斥

    QAction *action = toolbar->addAction(QIcon(":/res/line.png"),
                                         "Draw a Line",
                                         this,SLOT(onDrawLineAct()));

    action->setCheckable(true);//可选中的，能有选中状态
    action->setChecked(true);//已经选中，默认选中
    action->setActionGroup(actionGroup);//关联到actiongroup

    action = toolbar->addAction(QIcon(":/res/rectangle.png"),
                                "Draw a Rectangle",
                                this,
                                SLOT(onDrawRectangleAct()));
    action->setCheckable(true);
    action->setActionGroup(actionGroup);

    action = toolbar->addAction(QIcon(":/res/circle.png"),
                                "Draw a circle",
                                this,
                                SLOT(onDrawCircleAct()));
    action->setCheckable(true);
    action->setActionGroup(actionGroup);

    action = toolbar->addAction(QIcon(":/res/triangle.png"),
                                "Draw a triangle",
                                this,
                                SLOT(onDrawRectangleAct()));
    action->setCheckable(true);
    action->setActionGroup(actionGroup);

    action = toolbar->addAction(QIcon(":/res/pencil.png"),
                                "Draw free",
                                this,
                                SLOT(onDrawFreeAct()));
    action->setCheckable(true);
    action->setActionGroup(actionGroup);

    m_scene = new PainterScene();
    auto *view = new PainterView(m_scene);//将view与scene关联,场景左上角一直与视图左上角重合

    setCentralWidget(view);


}

MainWindow::~MainWindow()
{

}

void MainWindow::onDrawLineAct(){
    m_scene->setToolType(tt_Line);
}

void MainWindow::onDrawRectangleAct(){
    //to do
}

void MainWindow::onDrawCircleAct(){
    //to do
}

void MainWindow::onDrawTriangleAct(){
    //to do
}

void MainWindow::onDrawFreeAct(){
    //to do
}

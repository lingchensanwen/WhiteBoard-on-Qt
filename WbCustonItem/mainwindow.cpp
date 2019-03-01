#include "mainwindow.h"
#include <QtWidgets>
#include "checkbox.h"

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

    QGraphicsScene *scene = new QGraphicsScene();
    QGraphicsView *view = new QGraphicsView(scene);//将view与scene关联,场景左上角一直与视图左上角重合
    view->setFixedSize(500, 300);
    scene->setSceneRect(0, 0, 800, 500);//设置场景比view大，看一下效果,场景左上角坐标(0, 0)，width = 800，height = 500
    view->setSceneRect(150, 100, 500, 300);//能看见的场景区域,视图左上角坐标(150, 100)，width = 500，height = 300
    setCentralWidget(view);

    QPen textPen(Qt::red);
    QPen rectPen(Qt::blue);
    QBrush rectBrush(Qt::green);
    QFont textFont(font());
    textFont.setPointSize(20);

    auto text1 = new QGraphicsSimpleTextItem("SimpleTextItem, Item, Item");
    text1->setPos(200, 230);//设置场景中坐标
    text1->setPen(textPen);
    text1->setZValue(100);//遮挡顺序
    scene->addItem(text1);

    auto rect = new QGraphicsRectItem(180, 110, 260, 100);//场景中坐标(200, 200)开始，宽高...
    rect->setPen(rectPen);
    rect->setBrush(rectBrush);
    rect->setZValue(10);
    scene->addItem(rect);

    rect = new QGraphicsRectItem(160, 180, 100, 100);
    rect->setPen(textPen);
    rect->setBrush(rectBrush);
    rect->setZValue(15);
    rect->setOpacity(0.5);
    scene->addItem(rect);

    auto check = new CheckBoxItem(250, 36, "I like Qt",
                                  ":/res/checked.png",
                                  ":/res/empty.png");
    check->setPos(160, 300);
    check->setFlag(QGraphicsItem::ItemIsFocusable, true);//设置焦点处理键盘事件
    check->setFocus();
    check->setZValue(120);
    scene->addItem(check);
    connect(check, &CheckBoxItem::stateChanged,
            [=](bool checked){
        qDebug() << "checked - " <<checked;
    });
}

MainWindow::~MainWindow()
{

}

void MainWindow::onDrawLineAct(){
    //to do
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

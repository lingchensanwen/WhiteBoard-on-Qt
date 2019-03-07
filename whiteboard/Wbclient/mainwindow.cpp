#include "mainwindow.h"
#include <QtWidgets>
#include "checkbox.h"
#include "painterscene.h"
#include "painterview.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), m_scene(nullptr)
    , m_conn(nullptr), m_toolBar(nullptr), m_nameEdit(nullptr)
{
    prepareJoinUI();
}

MainWindow::~MainWindow()
{

}

void MainWindow::prepareJoinUI(){
    QWidget *widget = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(widget);
    QLabel *namelabel = new QLabel("Input Your Name:");
    layout->addWidget(namelabel);

    m_nameEdit = new QLineEdit("nana");
    layout->addWidget(m_nameEdit);

    auto btn = new QPushButton("Join");
    connect(btn, SIGNAL(clicked(bool)), this, SLOT(onJoinButtonClicked()));
    layout->addWidget(btn);

    layout->addStretch(1);

    setCentralWidget(widget);

}

void MainWindow::preparePainterUI(){
    if(!m_toolBar)
    {
        QToolBar *toolbar = addToolBar("Figure Type");
        QActionGroup *actionGroup = new QActionGroup(toolbar);//加到一个组中，可以设定选择或者互斥
        m_toolBar = toolbar;

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
                                    SLOT(onDrawTriangleAct()));
        action->setCheckable(true);
        action->setActionGroup(actionGroup);

        action = toolbar->addAction(QIcon(":/res/pencil.png"),
                                    "Draw free",
                                    this,
                                    SLOT(onDrawFreeAct()));
        action->setCheckable(true);
        action->setActionGroup(actionGroup);
        //删除上一个
        toolbar->addSeparator();//分隔符

        action = toolbar->addAction(QIcon(":/res/return.png"), "Deleted lastest added figure"
                                    ,this, SLOT(onUndo()));
        action->setActionGroup(actionGroup);
        //清除
        action = toolbar->addAction(QIcon(":/res/clearall.png"), "Clear All"
                                    ,this, SLOT(onClearAll()));
        action->setActionGroup(actionGroup);

    }
    else{
        addToolBar(m_toolBar);
    }
    m_scene = new PainterScene();
    auto *view = new PainterView(m_scene);//将view与scene关联,场景左上角一直与视图左上角重合

    connect(m_scene, SIGNAL(addFigureReq(QJsonObject)),
            this, SLOT(onAddFigureReq(QJsonObject)));
    connect(m_scene, SIGNAL(deleteFigureReq(int)),
            this, SLOT(onDeleteFigureReq(int)));
    connect(m_scene, SIGNAL(clearFigureReq(int)),
            this, SLOT(onClearFigureReq(int)));

    setCentralWidget(view);
}
void MainWindow::onDrawLineAct(){
    m_scene->setToolType(tt_Line);
}

void MainWindow::onDrawRectangleAct(){
    m_scene->setToolType(tt_Rectangle);
}

void MainWindow::onDrawCircleAct(){
    m_scene->setToolType(tt_Circle);
}

void MainWindow::onDrawTriangleAct(){
    m_scene->setToolType(tt_Triangle);
}

void MainWindow::onDrawFreeAct(){
    m_scene->setToolType(tt_Graffiti);
}

void MainWindow::onUndo(){
    m_scene->undo();
}

void MainWindow::onClearAll(){
    if(m_conn) m_conn->ClearFigures(-1);
}


void MainWindow::onJoinButtonClicked(){
    if(!m_conn){
        m_conn = new WbConnect(this);//创建连接去连接服务器
        QString strName = m_nameEdit->text();
        connect(m_conn, SIGNAL(joined(QString,int)),
                this, SLOT(onJoined(QString,int)));
        connect(m_conn, SIGNAL(someoneleft(QString,int)),
                this, SLOT(onSomeoneleft(QString,int)));
        connect(m_conn, SIGNAL(figureAdded(QJsonObject)),
                this, SLOT(onFigureAdded(QJsonObject)));
        connect(m_conn, SIGNAL(figureDeleted(int)),
                this, SLOT(onFigureDeleted(int)));
        connect(m_conn, SIGNAL(figureCleared(int)),
                this, SLOT(onFigureCleared(int)));
        m_conn->join(strName, "127.0.0.1", 1996);
    }
}

void MainWindow::onJoined(QString m_name, int id){
    if(id == m_conn->id()){//自己加入聊天室成功，准备preparePainterUI
        m_nameEdit = nullptr;
        preparePainterUI();
        m_scene->setUserId(id);
    }
    else{
        //To do
    }
}

void MainWindow::onSomeoneleft(QString name, int id){
    if(id == m_conn->id()){//自己退出成功，preparePainterUI重置，移除toolBar，调用prepareJoinUI
        m_scene = nullptr;
        removeToolBar(m_toolBar);
        prepareJoinUI();
    }
    else{
        //To do
    }
}

void MainWindow::onFigureAdded(const QJsonObject &figure){
    m_scene->onFigureAdded(figure);//让scene来处理
}

void MainWindow::onFigureDeleted(int id){
    m_scene->onFigureDeleted(id);
}

void MainWindow::onFigureCleared(int OwnerId){
    m_scene->onFigureCleared(OwnerId);
}

void MainWindow::onErrorOccurred(const QString &desc){
    prepareJoinUI();
    //若出错，重置
    if(m_conn){
        m_conn->deleteLater();
        m_conn = nullptr;
    }
}

void MainWindow::onAddFigureReq(const QJsonObject &figure){//MainWindow桥接网络和UI
    if(m_conn) m_conn->AddFigure(figure);//直接转发给wbconnect(服务器）
}

void MainWindow::onDeleteFigureReq(int id){
    if(m_conn) m_conn->DeleteFigure(id);
}

void MainWindow::onClearFigureReq(int ownerId){
    if(m_conn) m_conn->ClearFigures(ownerId);
}

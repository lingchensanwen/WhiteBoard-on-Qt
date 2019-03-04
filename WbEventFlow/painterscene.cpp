#include "painterscene.h"
#include <QDebug>

PainterScene::PainterScene(QObject *parent): QGraphicsScene(parent)
{

}

PainterScene::~PainterScene(){}

void PainterScene::mousePressEvent(QGraphicsSceneMouseEvent *ev){
    qDebug() << "PainterScene::mousePressEvent";
    QGraphicsScene::mousePressEvent(ev);
}

void PainterScene::mouseMoveEvent(QGraphicsSceneMouseEvent *ev){
    qDebug() << "PainterScene::mouseMoveEvent";
    QGraphicsScene::mouseMoveEvent(ev);
}

void PainterScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *ev){
    qDebug() << "PainterScene::mouseReleaseEvent";
    QGraphicsScene::mouseReleaseEvent(ev);
}

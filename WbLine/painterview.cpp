#include "painterview.h"
#include <QResizeEvent>
#include <QDebug>

PainterView::PainterView(QGraphicsScene *scene, QWidget *parent):
    QGraphicsView(scene, parent){

    setRenderHint(QPainter::Antialiasing, true);//反锯齿提示，使绘制更加平滑
}
#if 0
void PainterView::mousePressEvent(QMouseEvent *ev){
    qDebug() << "PainterView::mousePressEvent";
    QGraphicsView::mousePressEvent(ev);
}

void PainterView::mouseMoveEvent(QMouseEvent *ev){
    qDebug() << "PainterView::mouseMoveEvent";
    QGraphicsView::mouseMoveEvent(ev);
}

void PainterView::mouseReleaseEvent(QMouseEvent *ev){
    qDebug() << "PainterView::mouseReleaseEvent";
    QGraphicsView::mouseReleaseEvent(ev);
}

void PainterView::resizeEvent(QResizeEvent *event){
    QGraphicsView::resizeEvent(event);
    const QSize &size = event->size();
    auto s = scene();
    if(s != NULL){//若view已经关联scene，改变scene大小
        QRectF rc(0, 0, size.width(), size.height());
        setSceneRect(rc);//设置viw的SceneRect
        s->setSceneRect(rc);//设置scene的SceneRect
    }

}
#endif

#ifndef PAINTERVIEW_H
#define PAINTERVIEW_H

#include <QGraphicsView>

class PainterView : public QGraphicsView{

public:
    PainterView(QGraphicsScene *scene, QWidget *parent =0);

protected:
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseMoveEvent(QMouseEvent *ev) override;
    void mouseReleaseEvent(QMouseEvent *ev) override;
    void resizeEvent(QResizeEvent *event) override;

};
#endif // PAINTERVIEW_H

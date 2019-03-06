#ifndef PAINTERSCENE_H
#define PAINTERSCENE_H

#include <QGraphicsScene>
#include "shape.h"

class PainterScene: public QGraphicsScene{
    Q_OBJECT
public:
    PainterScene(QObject *parent = 0);
    ~PainterScene();

    void setToolType(int type);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *ev) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *ev) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *ev) override;

protected:
    int m_toolType;
    Shape *m_currentShape;

};
#endif // PAINTERSCENE_H

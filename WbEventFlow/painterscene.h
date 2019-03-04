#ifndef PAINTERSCENE_H
#define PAINTERSCENE_H

#include <QGraphicsScene>

class PainterScene: public QGraphicsScene{
    Q_OBJECT
public:
    PainterScene(QObject *parent = 0);
    ~PainterScene();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *ev) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *ev) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *ev) override;

};
#endif // PAINTERSCENE_H

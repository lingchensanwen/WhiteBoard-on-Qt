#ifndef PAINTERSCENE_H
#define PAINTERSCENE_H

#include <QGraphicsScene>
#include "shape.h"
#include <QJsonObject>
#include <list>

class PainterScene: public QGraphicsScene{
    Q_OBJECT
public:
    PainterScene(QObject *parent = 0);
    ~PainterScene();

    void setToolType(int type);

    void setUserId(int id){m_id = id ;}//提供对外接口来设置id
    void onFigureAdded(const QJsonObject &figure);
    void onFigureDeleted(int id);
    void onFigureCleared(int OwnerId);
    void undo();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *ev) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *ev) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *ev) override;

signals:
    void addFigureReq(const QJsonObject &figure);//绘制完一个图形发射信号给服务器
    void deleteFigureReq(int id);
    void clearFigureReq(int OwnerId);

protected:
    int m_toolType;
    int m_id;
    Shape *m_currentShape;
    std::list<Shape*> m_shapes;//保存所有图形

};
#endif // PAINTERSCENE_H

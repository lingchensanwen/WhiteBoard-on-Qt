#include "shape.h"


//SLine

SLine::SLine() : Shape(tt_Line), m_rcBounding(0, 0, 0, 0)
{}

void SLine::setStartPoint(const QPointF &pos){

    setPos(pos);
    m_startPosScene = pos;//保存位置值
}

void SLine::setEndPoint(const QPointF &pos){
    m_endPosScene = pos;

    qreal endX = m_endPosScene.x();
    qreal endY = m_endPosScene.y();
    qreal startX = m_startPosScene.x();
    qreal startY = m_startPosScene.y();

    m_rcBounding.setWidth(qAbs(endX - startX));
    m_rcBounding.setHeight(qAbs(endY - startY));

    QPointF startPoint;//线段起点
    QPointF endPoint;//线段终点

    if(endX < startX){
        startX = endX;//startX是item左上角的位置
        startPoint.setX(m_rcBounding);

    }

}

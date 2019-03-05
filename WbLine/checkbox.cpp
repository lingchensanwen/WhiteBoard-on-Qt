#include "checkbox.h"
#include <QPainter>
#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

CheckBoxItem::CheckBoxItem(int w, int h, const QString &text, const QString &checkedIcon, const QString &emptyIcon, QGraphicsItem *parent)
    : QGraphicsObject(parent)
    ,m_text(text)
    ,m_width(w), m_height(h)
    ,m_checked(false)
    ,m_checkedIcon(checkedIcon), m_emptyIcon(emptyIcon)
    ,m_leftButtonDown(false)
{

}

QRectF CheckBoxItem::boundingRect() const{
    return QRectF(0, 0, m_width, m_height);
}

void CheckBoxItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    int x = 2;
    int y = (m_height - m_checkedIcon.height()) / 2;//在图表中y方向居中
    painter->drawPixmap(x, y, m_checked? m_checkedIcon : m_emptyIcon);//选中用选中图片，否则用未选中图片
    if(!m_text.isEmpty())//若文本不为空，进行文本绘制
    {
        x = x + m_checkedIcon.width() + 4;//在Icon基础上，进行偏移
        QRect rc(x, 0, m_width - x - 2, m_height);//包围文字的矩形绘制
        painter->drawText(rc, Qt::AlignVCenter | Qt::AlignLeft, m_text);//垂直居中，水平靠左
    }
}
//按下空格
void CheckBoxItem::keyPressEvent(QKeyEvent *ev){
    if(ev->key() == Qt::Key_Space){
        ev->accept();//处理这个事件
        m_checked = !m_checked;//checked标记反转一下
        update();//update来重绘Item
        emit stateChanged(m_checked);//发出状态变化信号，将状态传递出去
    }
}
//按下鼠标左键
void CheckBoxItem::mousePressEvent(QGraphicsSceneMouseEvent *ev){
    qDebug() << "CheckBoxItem::mousePressEvent";
    if(ev->button() == Qt::LeftButton){
        m_leftButtonDown = true;
        ev->accept();
    }
}
//松开鼠标左键
void CheckBoxItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *ev){
    qDebug() << "CheckBoxItem::mouseReleaseEvent";
    if(ev->button() == Qt::LeftButton && m_leftButtonDown){
        m_leftButtonDown = false;
        m_checked = !m_checked;
        ev->accept();
        update();
        emit stateChanged(m_checked);
    }
}

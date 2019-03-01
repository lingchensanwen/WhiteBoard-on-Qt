#ifndef CHECKBOX_H
#define CHECKBOX_H
#include <QGraphicsItem>
#include <QGraphicsObject>
class CheckBoxItem : public QGraphicsObject{
    Q_OBJECT
public:
    CheckBoxItem(int w, int h, const QString &text, const QString &checkedIcon,
                 const QString &emptyIcon, QGraphicsItem *parent = 0);
    //checkedIcon, emptyIcon存对应路径
    QRectF boundingRect() const override;//重载，重写父类
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    //对外API
    bool isChecked();//是否是选中状态
    void setChecked(bool checked);//设定是否是选中状态

signals:
    void stateChanged(bool checked);//被选中时候，发射信号，checked参数用于告知我们

protected:
    //支持键盘和鼠标
    void keyPressEvent(QKeyEvent *ev) override;//重载，重写父类
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;//重载，重写父类
    //从QGraphicsSceneMouseEvent中可以看出，QWidget中事件均被转换到scene中事件
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    //定义其他数据文本
    QString m_text;
    int m_width;
    int m_height;
    bool m_checked;
    QPixmap m_checkedIcon;//QPixmap可以接受一个字符串作为一个文件的路径来显示这个文件
    QPixmap m_emptyIcon;
    bool m_leftButtonDown;//鼠标左键是否被按下
};

#endif // CHECKBOX_H

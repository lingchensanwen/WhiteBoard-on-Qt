#ifndef SHAPE_H
#define SHAPE_H

#include <QtWidgets>
#endif // SHAPE_H
enum ToolType {
    tt_Line = 1,
    tt_Graffiti,
    tt_Rectangle,
    tt_Circle,
    tt_Triangle
};

class Shape: public QGraphicsItem{

public:
    Shape(int type): m_type(type)
      , m_strokeWidth(1.0f)
      , m_strokeColor(Qt::black)
      , m_fillColor(Qt::transparent)//填充透明
      , m_creatorId(-1)
      , m_globalId(-1)
      , m_localId(gernerateLocalId())
      {}

    virtual ~Shape(){}//程序基类，虚构函数

    virtual void setStartPoint(const QPointF &pos) = 0;//纯虚函数成员, 这样的基类无法实例化, 子类必须实现这些函数
    virtual void setEndPoint(const QPointF &pos) = 0;//纯虚函数成员, 这样的基类无法实例化, 子类必须实现这些函数
    virtual void setStrokeWidth(float w) {m_strokeWidth = w; }
    virtual void setStrokeColor(const QColor &color) {m_strokeColor = color ;}
    virtual void setFillColor(const QColor &color) {m_fillColor = color; }
    virtual bool isValid(){ return true; }//判断图形是否有效
    virtual void serialize(QJsonObject &obj) = 0;//接收QJsonObject，新绘制的图形

    static int gernerateLocalId();

    //设置并获取creatorId
    void setCreatorId(int id){ m_creatorId = id;}
    int creatorId(){ return m_creatorId;}
    //设置并获取globalId
    void setGlobalId(int id){ m_globalId = id;}
    int globalId(){ return m_globalId;}
    //设置并获取localId
    void setLocalId(int id){ m_localId = id;}
    int localId(){return m_localId;}

protected:
    int m_type;//成员变量，类型
    float m_strokeWidth;//线段宽度
    QColor m_strokeColor;//线段颜色
    QColor m_fillColor;//填充颜色
    static int m_idBase;
    int m_creatorId;
    int m_globalId;
    int m_localId;
};

class SLine: public Shape{

public:
    SLine();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void setStartPoint(const QPointF &pos) override;
    void setEndPoint(const QPointF &pos) override;
    void setStrokeWidth(float w) override;
    void setStrokeColor(const QColor &color) override;
    bool isValid() override;
    void serialize(QJsonObject &obj) override;

protected:
    QPointF m_startPosScene;
    QPointF m_endPosScene;
    QLineF m_line;
    QRectF m_rcBounding;
    QPen m_pen;
};

class SRectangle: public Shape{

public:
    SRectangle(int type = tt_Rectangle);//椭圆和三角以矩形为标准绘制

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void setStartPoint(const QPointF &pos) override;
    void setEndPoint(const QPointF &pos) override;
    void setStrokeWidth(float w) override;
    void setStrokeColor(const QColor &color) override;
    void setFillColor(const QColor &color) override;
    bool isValid() override;
    void serialize(QJsonObject &obj) override;

protected:
    QPointF m_startPosScene;
    QPointF m_endPosScene;
    QRectF m_rcBounding;
    QPen m_pen;

};
//SOval
class SOval : public SRectangle{

public:

    SOval();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};
//STriangle
class STriangle: public SRectangle{

public:
    STriangle();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

//Draw Free
class SGraffiti: public Shape{

public:
    SGraffiti();


    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void setStartPoint(const QPointF &pos) override;
    void setEndPoint(const QPointF &pos) override;
    void setStrokeWidth(float w) override;
    void setStrokeColor(const QColor &color) override;
    bool isValid() override;
    void serialize(QJsonObject &obj) override;//图形信息系列化到Json中去
    void setPath(QPainterPath &path);

protected:
    QPointF m_startPosScene;
    QPointF m_endPosScene;
    QRectF m_rcBounding;
    QPen m_pen;
    QPainterPath m_path;
    QPointF m_topLeftInScene;

};

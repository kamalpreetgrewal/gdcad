#ifndef CIRCLE_H
#define CIRCLE_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

class circle: public QGraphicsItem
{
public:
    circle();
    QRectF boundingRect() const;
    virtual void paint(QPainter * painter,
                       const QStyleOptionGraphicsItem * option,
                       QWidget * widget);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *e);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *e);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *e);

private:
    QVector<QPointF> stuff;
};

#endif // CIRCLE_H

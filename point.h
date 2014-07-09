#ifndef POINT_H
#define POINT_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

class point: public QGraphicsItem
{
public:
    point();
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

#endif // POINT_H

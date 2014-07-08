#ifndef POINT_H
#define POINT_H

#include <QPainter>
#include <QGraphicsItem>

class point: public QGraphicsItem
{
public:
    point();
    QRectF boundingRect() const;
    virtual void paint(QPainter * painter,
                       const QStyleOptionGraphicsItem * option,
                       QWidget * widget);
};

#endif // POINT_H

#ifndef ELLIPSE_H
#define ELLIPSE_H
#include <QPainter>
#include <QGraphicsItem>

class ellipse: public QGraphicsItem
{
public:
    ellipse();
    QRectF boundingRect() const;
    virtual void paint(QPainter * painter,
                       const QStyleOptionGraphicsItem * option,
                       QWidget * widget);
};

#endif // ELLIPSE_H

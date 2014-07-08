#include "point.h"

point::point()
{
}

QRectF point::boundingRect() const
{
    // outer most edges
    return QRectF(0,0,100,100);
}

void point:: paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QRectF rect = boundingRect();
    QPen pen(Qt::black, 1);
    painter->setPen(pen);
    painter->drawPoint(100,100);
}

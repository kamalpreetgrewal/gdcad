#include "circle.h"

circle::circle()
{
}

QRectF circle::boundingRect() const
{
    // outer most edges
    return QRectF(0,0,100,100);
}

void circle:: paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QRectF rect = boundingRect();
    QPen pen(Qt::black, 1);
    painter->setPen(pen);
    int x = 0 * 16;
    int y = 360 * 16;
    painter->drawArc(10,10,100,100,x,y);
}

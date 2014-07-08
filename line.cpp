#include "line.h"

line::line()
{

}

QRectF line::boundingRect() const
{
    // outer most edges
    return QRectF(0,0,100,100);
}

void line:: paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QRectF rect = boundingRect();
    QPen pen(Qt::black, 1);
    painter->setPen(pen);
    painter->drawLine(100,100,20,200);
}

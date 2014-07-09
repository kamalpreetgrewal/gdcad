#include "circle.h"

circle::circle()
{
    setFlags(ItemIsSelectable | ItemIsMovable);
    setAcceptHoverEvents(true);
}

QRectF circle::boundingRect() const
{
    // outer most edges
    return QRectF(0,0,300,300);
}

void circle:: paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QRectF rect = boundingRect();
    QPen pen(Qt::black, 1);
    painter->setPen(pen);
    int x = 0 * 16;
    int y = 360 * 16;
    painter->drawArc(10,10,100,100,x,y);
}

void circle::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
    update();
}
void circle::mouseMoveEvent(QGraphicsSceneMouseEvent *e)
{
    if (e->modifiers() & Qt::ShiftModifier) {
        stuff << e->pos();
        update();
        return;
    }
    QGraphicsItem::mouseMoveEvent(e);
}

void circle::mouseReleaseEvent(QGraphicsSceneMouseEvent *e)
{
    QGraphicsItem::mouseReleaseEvent(e);
    update();
}

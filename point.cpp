#include "point.h"

point::point()
{
    setFlags(ItemIsSelectable | ItemIsMovable);
    setAcceptHoverEvents(true);
}

QRectF point::boundingRect() const
{
    // outer most edges
    return QRectF(0,0,100,100);
}

void point:: paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QRectF rect = boundingRect();
    QPen pen(Qt::black, 4);
    painter->setPen(pen);
    painter->drawPoint(100,100);
}

void point::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
    update();
}
void point::mouseMoveEvent(QGraphicsSceneMouseEvent *e)
{
    if (e->modifiers() & Qt::ShiftModifier) {
        stuff << e->pos();
        update();
        return;
    }
    QGraphicsItem::mouseMoveEvent(e);
}

void point::mouseReleaseEvent(QGraphicsSceneMouseEvent *e)
{
    QGraphicsItem::mouseReleaseEvent(e);
    update();
}

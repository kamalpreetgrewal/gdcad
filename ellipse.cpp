#include "ellipse.h"

ellipse::ellipse()
{
    setFlags(ItemIsSelectable | ItemIsMovable);
    setAcceptHoverEvents(true);
}

QRectF ellipse::boundingRect() const
{
    // outer most edges
    return QRectF(0,0,300,300);
}

void ellipse:: paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QRectF rect = boundingRect();
    QPen pen(Qt::black, 1);
    painter->setPen(pen);
    int x = 0 * 16;
    int y = 360 * 16;
    painter->drawArc(10,10,200,100,x,y);
}

void ellipse::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
    update();
}
void ellipse::mouseMoveEvent(QGraphicsSceneMouseEvent *e)
{
    if (e->modifiers() & Qt::ShiftModifier) {
        stuff << e->pos();
        update();
        return;
    }
    QGraphicsItem::mouseMoveEvent(e);
}

void ellipse::mouseReleaseEvent(QGraphicsSceneMouseEvent *e)
{
    QGraphicsItem::mouseReleaseEvent(e);
    update();
}

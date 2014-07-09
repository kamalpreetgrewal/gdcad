#include "point.h"

point::point()
{
    x1 = 0;
    y1 = 0;

    mFirstClick = true;
    setFlags(ItemIsSelectable );
    setAcceptHoverEvents(true);
}

QRectF point::boundingRect() const
{
    // outer most edges
    return QRectF(0,0,300,300);
}

void point:: paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QRectF rect = boundingRect();
    QPen pen(Qt::black, 4);

    if(mPaintFlag){

        QPen paintpen(Qt::red);
        paintpen.setWidth(1);

        QPen linepen(Qt::black);
        linepen.setWidth(1);

        QPoint p1;
        p1.setX(x1);
        p1.setY(y1);

        painter->setPen(paintpen);
        painter->drawPoint(p1);



        painter->setPen(linepen);
        painter->drawPoint(x1, y1);
    }
}

void point::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    if(e->button()==Qt::LeftButton) {
        if(mFirstClick){
            x1 = e->pos().x();
            y1 = e->pos().y();
            mFirstClick = false;
        }

        else if(!mFirstClick){
            x2 = e->pos().x();
            y2 = e->pos().y();
            mFirstClick = true;
            mPaintFlag = true;
            update();
        }
   }
    QGraphicsItem::mousePressEvent(e);
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

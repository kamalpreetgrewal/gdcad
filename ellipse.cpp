#include "ellipse.h"

ellipse::ellipse()
{
    x1 = 0;
    y1 = 0;
    x2 = 0;
    y2 = 0;
    mFirstClick = true;
    setFlags(ItemIsSelectable);
    setAcceptHoverEvents(true);
}

QRectF ellipse::boundingRect() const
{
    // outer most edges
    return QRectF(0,0,800,800);
}


void ellipse:: paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QRectF rect = boundingRect();
        QPen pen(Qt::black, 1);
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

        QPoint p2;
        p2.setX(x2);
        p2.setY(y2);

        painter->setPen(paintpen);
        painter->drawPoint(p2);

        painter->setPen(linepen);
        int x = 0 * 16;
        int y = 360 * 16;
        painter->drawArc(x1,y1,x2,y2,x,y);
    }

}

void ellipse::mousePressEvent(QGraphicsSceneMouseEvent *e)
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

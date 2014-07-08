#include "line.h"
#include <QDebug>

line::line()
{
    x1 = 0;
    y1 = 0;
    x2 = 0;
    y2 = 0;
    mFirstClick = true;
}

QRectF line::boundingRect() const
{
    // outer most edges
    return QRectF(0,0,100,100);
}
void line::mousePressEvent(QGraphicsSceneMouseEvent* e){
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
}


void line:: paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
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
        painter->drawLine(p1, p2);
    }
}

//void line::wheelEvent(QGraphicsSceneWheelEvent *e){
//    m_scale += e->delta() / qreal(600);
//        m_scale = qMax(qreal(0.1), qMin(qreal(4), m_scale));
//        emit scaleChanged(int(m_scale*1000));
//}

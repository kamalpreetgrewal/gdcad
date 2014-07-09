#ifndef ELLIPSE_H
#define ELLIPSE_H
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

class ellipse: public QGraphicsItem
{
public:
    ellipse();
    QRectF boundingRect() const;
    virtual void paint(QPainter * painter,
                       const QStyleOptionGraphicsItem * option,
                       QWidget * widget);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *e);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *e);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *e);

private:
    QVector<QPointF> stuff;
};

#endif // ELLIPSE_H

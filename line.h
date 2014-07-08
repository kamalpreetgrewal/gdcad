#ifndef LINE_H
#define LINE_H

#include <QPainter>
#include <QGraphicsItem>

class line:public QGraphicsItem
{
public:
    line();
    QRectF boundingRect() const;
    virtual void paint(QPainter * painter,
                       const QStyleOptionGraphicsItem * option,
                       QWidget * widget);
};

#endif // LINE_H

#ifndef POINT_H
#define POINT_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include "ui_mainwindow.h"

class point: public QGraphicsItem
{
public:
    point();
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
    int x1, y1;
    bool mClick;
    bool mPaintFlag;
    bool Pressed;
    QPoint *mousePoint;
    Ui::MainWindow *ui;
    qreal m_scale;
};

#endif // POINT_H

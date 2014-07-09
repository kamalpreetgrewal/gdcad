#ifndef CIRCLE_H
#define CIRCLE_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include "ui_mainwindow.h"

class circle: public QGraphicsItem
{
public:
    circle();
    QRectF boundingRect() const;
    virtual void paint(QPainter * painter,
                       const QStyleOptionGraphicsItem * option,
                       QWidget * widget);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *e);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *e);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *e);

private:
    int x1, y1, x2, y2;
    bool mFirstClick;
    bool mPaintFlag;
    bool Pressed;
    QPoint *mousePoint;
 Ui::MainWindow *ui;
    qreal m_scale;

public slots:
    void changeScale(int scale);

signals:
    void scaleChanged(int scale);


private:
    QVector<QPointF> stuff;
};

#endif // CIRCLE_H

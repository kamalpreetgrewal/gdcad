#ifndef ELLIPSE_H
#define ELLIPSE_H
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include "ui_mainwindow.h"
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
};

#endif // ELLIPSE_H

#ifndef LINE_H
#define LINE_H

#include <QPainter>
#include <QGraphicsItem>
#include <QMouseEvent>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include "ui_mainwindow.h"

class line: public QGraphicsItem
{
public:
    line();
    QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    qreal scale() const { return m_scale; }
    void setScale(qreal s);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *e);

public slots:
    void changeScale(int scale);

signals:
    void scaleChanged(int scale);

private:
    int x1, y1, x2, y2;
    bool mFirstClick;
    bool mPaintFlag;
    bool Pressed;
    QPoint *mousePoint;
    Ui::MainWindow *ui;
    qreal m_scale;


};

#endif // LINE_H

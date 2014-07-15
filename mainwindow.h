#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>

#include "line.h"
#include "circle.h"
#include "ellipse.h"
#include "point.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void wheelEvent(QWheelEvent* event);

private:
    Ui::MainWindow *ui;
    bool mFirstClick;
    bool mPaintFlag;
    int mStartX;
    int mStartY;
    int mEndX;
    int mEndY;
    QGraphicsScene *scene;
    QPainter *painter;
    point *item;
    line *item1;
    circle *item2;
    ellipse *item3;
    arc *item4;
    bool eventFilter(QObject *obj, QEvent *event);

private slots:
    void drawPoint();
    void drawLine();
    void drawCircle();
    void drawEllipse();
    void drawArc();
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPaintEvent>
#include <QGraphicsScene>
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
    void mousePressEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *);

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

private slots:
    void drawLine();
    void drawPoint();
    void drawCircle();
    void drawEllipse();

};

#endif // MAINWINDOW_H

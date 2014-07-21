#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrintPreviewDialog>
#include <QPainter>
#include <QRectF>

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
    void paintGrid(QPainter* painter, const QRectF& rect);
    QGraphicsScene *scene;

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

    QPainter *painter;
    point *item;
    line *item1;
    circle *item2;
    ellipse *item3;
    bool eventFilter(QObject *obj, QEvent *event);
    QPrinter *printer;

private slots:
    void drawPoint();
    void drawLine();
    void drawCircle();
    void drawEllipse();

public slots:
    void filePrintPreview();
    void filePrint();
    void print(QPrinter *);

};

#endif // MAINWINDOW_H

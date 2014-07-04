#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), mStartX(0), mStartY(0), mEndX(0), mEndY(0), mFirstClick(true), mPaintFlag(false),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("GD CAD"));
    ui->setupUi(this);
}

void MainWindow::mousePressEvent(QMouseEvent * e)
{
    if(e->button() == Qt::LeftButton)
    {
        //store 1st point
        if(mFirstClick)
        {
            mStartX = e->x();
            mStartY = e->y();
            mFirstClick = false;
        }
        //Mouse Pressed Again! 2nd point
        else if(!mFirstClick)
        {
            mEndX = e->x();
            mEndY = e->y();
            mFirstClick = true;
            mPaintFlag = true;
            update();
        }
    }
}
void MainWindow::paintEvent(QPaintEvent * e)
{

    if(mPaintFlag)
    {
        QPainter painter(this);
        QPen paintpen(Qt::red);
        paintpen.setWidth(1);

        QPen linepen(Qt::black);
        linepen.setWidth(1);

        QPoint p1;
        p1.setX(mStartX);
        p1.setY(mStartY);

        painter.setPen(paintpen);
        painter.drawPoint(p1);

        QPoint p2;
        p2.setX(mEndX);
        p2.setY(mEndY);

        painter.setPen(paintpen);
        painter.drawPoint(p2);

        painter.setPen(linepen);
        painter.drawLine(p1, p2);
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}







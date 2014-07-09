#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMouseEvent>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), mStartX(0), mStartY(0), mEndX(0), mEndY(0), mFirstClick(true), mPaintFlag(false),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("GD CAD"));
    scene =  new QGraphicsScene;
    for(int x = 0; x <= ui->graphicsView->width(); x += 10){
        scene->addLine(x,0,x,ui->graphicsView->height(),QPen(Qt::green));
    }
    for(int y = 0; y <= ui->graphicsView->height(); y += 10){
        scene->addLine(0,y,ui->graphicsView->width(),y,QPen(Qt::green));
    }
    ui->graphicsView->setScene(scene);
    connect(ui->lineButton, SIGNAL(clicked()), this, SLOT(drawLine()));
    connect(ui->circleButton, SIGNAL(clicked()), this, SLOT(drawCircle()));
    connect(ui->pointButton, SIGNAL(clicked()), this, SLOT(drawPoint()));
    connect(ui->ellipseButton, SIGNAL(clicked()), this, SLOT(drawEllipse()));

}

void MainWindow::drawLine(){
    ui->graphicsView->setScene(scene);
    line *item = new line;
    scene->addItem(item);
    qDebug() << "Line Created";

}

void MainWindow::drawCircle(){
    ui->graphicsView->setScene(scene);
    circle *item = new circle;
    scene->addItem(item);
    qDebug() << "Circle Created";
}

void MainWindow::drawEllipse(){
    ui->graphicsView->setScene(scene);
    ellipse *item = new ellipse;
    scene->addItem(item);
    qDebug() << "Ellipse Created";
}

void MainWindow::drawPoint(){
    ui->graphicsView->setScene(scene);
    point *item = new point;
    scene->addItem(item);
    qDebug() << "Point Created";
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
    if(e->button() == Qt::MiddleButton)
    {
        ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
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

void MainWindow::wheelEvent(QWheelEvent* event) {

    ui->graphicsView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

    // Scale the view / do the zoom
    double scaleFactor = 1.15;
    if(event->delta() > 0) {
        // Zoom in
      ui->graphicsView->scale(scaleFactor, scaleFactor);
    } else {
        // Zooming out
        ui->graphicsView->scale(1.0 / scaleFactor, 1.0 / scaleFactor);
    }

}


MainWindow::~MainWindow()
{
    delete ui;
}







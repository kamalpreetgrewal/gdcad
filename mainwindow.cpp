#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMouseEvent>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
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

    for(int x = 10; x <= ui->graphicsView->width(); x += 100){
        scene->addLine(x,0,x,ui->graphicsView->height(),QPen(Qt::darkGreen));
    }

    for(int y = 10; y <= ui->graphicsView->height(); y += 100){
        scene->addLine(0,y,ui->graphicsView->width(),y,QPen(Qt::darkGreen));
    }

    qApp->installEventFilter(this);
    ui->graphicsView->setScene(scene);

    connect(ui->pointButton, SIGNAL(clicked()), this, SLOT(drawPoint()));
    connect(ui->lineButton, SIGNAL(clicked()), this, SLOT(drawLine()));
    connect(ui->circleButton, SIGNAL(clicked()), this, SLOT(drawCircle()));
    connect(ui->ellipseButton, SIGNAL(clicked()), this, SLOT(drawEllipse()));

    connect(ui->actionPoints, SIGNAL(triggered()), this, SLOT(drawPoint()));
    connect(ui->actionLine, SIGNAL(triggered()), this, SLOT(drawLine()));
    connect(ui->actionCircle, SIGNAL(triggered()), this, SLOT(drawCircle()));
    connect(ui->actionEllipse, SIGNAL(triggered()), this, SLOT(drawEllipse()));
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseMove)
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        statusBar()->showMessage(QString("Mouse move (%1,%2)").arg(mouseEvent->pos().x()).arg(mouseEvent->pos().y()));
    }
    return false;
}


void MainWindow::drawPoint(){
    ui->graphicsView->setScene(scene);
    item = new point;
    scene->addItem(item);
    qDebug() << "Point Created";
    connect(item, SIGNAL(DrawFinished()), this, SLOT(drawPoint()));
}

void MainWindow::drawLine(){
    ui->graphicsView->setScene(scene);
    item1 = new line;
    scene->addItem(item1);
    qDebug() << "Line Created";
    connect(item1, SIGNAL(DrawFinished()), this, SLOT(drawLine()));
}

void MainWindow::drawCircle(){
    ui->graphicsView->setScene(scene);
    item2 = new circle;
    scene->addItem(item2);
    qDebug() << "Circle Created";
    connect(item2, SIGNAL(DrawFinished()), this, SLOT(drawCircle()));
}

void MainWindow::drawEllipse(){
    ui->graphicsView->setScene(scene);
    item3 = new ellipse;
    scene->addItem(item3);
    qDebug() << "Ellipse Created";
    connect(item3, SIGNAL(DrawFinished()), this, SLOT(drawEllipse()));
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

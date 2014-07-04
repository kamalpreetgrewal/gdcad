#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("GD CAD"));
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->resize(600,500);

    ui->actionLine->connect(ui->actionLine,SIGNAL(triggered()),this,SLOT(drawLine()));
}
void MainWindow::drawLine(){
    scene->addLine(100,100,20,200);
}

MainWindow::~MainWindow()
{
    delete ui;
}







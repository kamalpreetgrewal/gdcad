#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QRect>
#include <QPainter>
#include <QMouseEvent>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("GD CAD"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    //a simple line
    painter.drawLine(100,100,200,200);

}



#include "drawarea.h"
#include "ui_drawarea.h"

drawarea::drawarea(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::drawarea)
{
    ui->setupUi(this);
}

drawarea::~drawarea()
{
    delete ui;
}

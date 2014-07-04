#ifndef DRAWAREA_H
#define DRAWAREA_H

#include <QWidget>

namespace Ui {
class drawarea;
}

class drawarea : public QWidget
{
    Q_OBJECT

public:
    explicit drawarea(QWidget *parent = 0);
    ~drawarea();

private:
    Ui::drawarea *ui;
};

#endif // DRAWAREA_H

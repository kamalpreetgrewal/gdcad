#ifndef STORAGE_H
#define STORAGE_H
#include <QPointF>

class storage
{
public:
    storage();
    ~storage();
    void set_point(QPointF);
    QPointF getValue();

private:
    QPointF _p;
};

#endif // STORAGE_H

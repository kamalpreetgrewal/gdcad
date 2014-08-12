#include "storage.h"

storage::storage()
{
}

storage::~storage()
{
}

void storage::set_point(QPointF p)
{
    _p = p;
}

QPointF storage::getValue()
{
    return _p;
}


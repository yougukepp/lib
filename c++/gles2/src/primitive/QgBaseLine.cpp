#include "QgBaseLine.h"

QgBaseLine::QgBaseLine(const std::vector<QgVertex> &points, QgColor c, float width)
    :QgPrimitive(points, c)
{
    SetLineWidth(width);
}


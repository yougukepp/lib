#include "QgBaseLine.h"

QgBaseLine::QgBaseLine(const std::vector<QgPoint> &points, QgColor c, float width)
    :QgPrimitive(points, c)
{
    SetLineWidth(width);
}


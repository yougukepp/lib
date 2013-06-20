#include "QgPolygon.h"

QgPolygon::QgPolygon(const std::vector<QgPoint> &points, QgColor c)
    :QgLines(points, c)
{
} 

void QgPolygon::Draw(void)
{
    QgPrimitive::Draw(GL_LINE_LOOP);
}


#include "QgPolygon.h"

QgPolygon::QgPolygon(const std::vector<QgPoint> &points, QgColor c)
    :QgLines(points, c)
{
} 

QgPolygon::QgPolygon(void)
    :QgLines()
{
}

QgPolygon::~QgPolygon(void)
{
    ;
}

void QgPolygon::Draw(void)
{
    QgPrimitive::Draw(GL_LINE_LOOP);
}


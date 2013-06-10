#include "GisPolygon.h"

GisPolygon::GisPolygon(const std::vector<GisPoint> &points, GisColor c)
    :GisLines(points, c)
{
} 

GisPolygon::GisPolygon(void)
    :GisLines()
{
}

/*
 * TODO: 参数检查
 */
void GisPolygon::Draw(void)
{
    GisLines::Draw(GL_LINE_LOOP);
}


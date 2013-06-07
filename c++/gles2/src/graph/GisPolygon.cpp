#include "GisPolygon.h"

GisPolygon::GisPolygon(const std::vector<GisPoint> &points)
    :GisLines(points)
{
}

/*
 * TODO: 参数检查
 */
void GisPolygon::draw(GisColor c)
{
    GisLines::draw(c, GL_LINE_LOOP);
}


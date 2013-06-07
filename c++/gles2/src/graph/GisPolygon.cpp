#include "GisPolygon.h"

GisPolygon::GisPolygon(void)
{
    ;
}

/*
 * TODO: 参数检查
 */
void GisPolygon::draw(std::vector<GisPoint> &points, GisColor &c)
{
    GisLines::draw(points, c, GL_LINE_LOOP);
}


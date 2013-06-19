#include "GisPolygon.h"

GisPolygon::GisPolygon(const std::vector<GisPoint> &points, GisColor c)
    :GisLines(points, c)
{
} 

GisPolygon::GisPolygon(void)
    :GisLines()
{
}

GisPolygon::~GisPolygon(void)
{
    ;
}

void GisPolygon::Draw(void)
{
    GisPrimitives::Draw(GL_LINE_LOOP);
}


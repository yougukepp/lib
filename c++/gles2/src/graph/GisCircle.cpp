#include "GisCircle.h"

GisCircle::GisCircle(GisPoint pOrig, double r, GisColor c)
    :GisLines()
{
    std::vector<GisPoint> points;
    GisArc::makePoints(points, pOrig, r, 0, 2 * GIS_PI);

    AddPoints(points);
    SetColor(c);
} 

void GisCircle::draw(void)
{
    GisLines::draw(GL_LINE_LOOP);
}


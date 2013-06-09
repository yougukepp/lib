#include "GisArc.h"

GisArc::GisArc(GisPoint pOrig, double r, double startAngle, double spanAngle, GisColor c)
    :GisLines()
{
    std::vector<GisPoint> points;
    GisCircle::makePoints(points, pOrig, r, startAngle, spanAngle);
    AddPoints(points);
    SetColor(c);
}

void GisArc::draw(void)
{
    GisLines::draw(GL_LINE_STRIP);
}


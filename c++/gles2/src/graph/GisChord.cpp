#include "GisChord.h"

GisChord::GisChord(GisPoint pOrig, double r, double startAngle, double spanAngle, GisColor c)
    :GisLines()
{
    std::vector<GisPoint> points;
    GisArc::makePoints(points, pOrig, r, startAngle, spanAngle);
    AddPoints(points);
    SetColor(c);
}

void GisChord::draw(void)
{
    GisLines::draw(GL_LINE_LOOP);
}


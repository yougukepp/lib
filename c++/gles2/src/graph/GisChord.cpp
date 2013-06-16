#include "GisChord.h"

GisChord::GisChord(GisPoint pOrig, double r, double startAngle, double spanAngle, GisColor c)
    :GisLines()
{
    std::vector<GisPoint> points;
    GisCircle::MakePoints(points, pOrig, r, startAngle, spanAngle);
    AddPoints(points);
    SetColor(c);
}

void GisChord::Draw(void)
{
    GisLines::Draw(GL_LINE_LOOP);
}


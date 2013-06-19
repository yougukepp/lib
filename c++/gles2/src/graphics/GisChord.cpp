#include "GisChord.h"

GisChord::GisChord(GisPoint pOrig, double r, double startAngle, double spanAngle, GisColor c)
    :GisLines()
{
    std::vector<GisPoint> points;
    GisCircle::MakePoints(points, pOrig, r, startAngle, spanAngle);
    AddPoints(points);
    SetColor(c);
}

GisChord::~GisChord(void)
{
    ;
}

void GisChord::Draw(void)
{
    GisPrimitives::Draw(GL_LINE_LOOP);
}


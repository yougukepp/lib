#include "GisArc.h"

GisArc::GisArc(GisPoint pOrig, double r, double startAngle, double spanAngle, GisColor c)
    :GisLines()
{
    std::vector<GisPoint> points;
    GisCircle::MakePoints(points, pOrig, r, startAngle, spanAngle);
    AddPoints(points);
    SetColor(c);
}

GisArc::~GisArc(void)
{
    ;
}

void GisArc::Draw(void)
{
    GisPrimitives::Draw(GL_LINE_STRIP);
}


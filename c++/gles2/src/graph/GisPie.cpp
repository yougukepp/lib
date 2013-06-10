#include "GisPie.h"

GisPie::GisPie(GisPoint pOrig, double r, double startAngle, double spanAngle, GisColor c)
    :GisLines()
{
    std::vector<GisPoint> points;
    GisCircle::MakePoints(points, pOrig, r, startAngle, spanAngle);
    points.push_back(pOrig);
    AddPoints(points);
    SetColor(c);
}

void GisPie::Draw(void)
{
    GisLines::Draw(GL_LINE_LOOP);
}


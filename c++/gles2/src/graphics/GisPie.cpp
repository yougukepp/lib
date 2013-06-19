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

GisPie::~GisPie(void)
{
    ;
}

void GisPie::Draw(void)
{
    GisPrimitives::Draw(GL_LINE_LOOP);
}


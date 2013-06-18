#include "GisCircle.h"

GisCircle::GisCircle(GisPoint pOrig, double r, GisColor c)
    :GisOval(pOrig, r, r, c)
{
} 

GisCircle::~GisCircle(void)
{
    ;
}

void GisCircle::Draw(void)
{
    GisPrimitives::Draw(GL_LINE_LOOP);
}

void GisCircle::MakePoints(std::vector<GisPoint> &points, GisPoint pOrig, double r,
        double startAngle, double spanAngle)
{
    GisOval::MakePoints(points, pOrig, r, r, startAngle, spanAngle);
}

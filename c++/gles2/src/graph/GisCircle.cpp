#include "GisCircle.h"

GisCircle::GisCircle(GisPoint pOrig, double r, GisColor c)
    :GisOval(pOrig, r, r, c)
{
} 

void GisCircle::draw(void)
{
    GisLines::draw(GL_LINE_LOOP);
}

void GisCircle::makePoints(std::vector<GisPoint> &points, GisPoint pOrig, double r,
        double startAngle, double spanAngle)
{
    GisOval::makePoints(points, pOrig, r, r, startAngle, spanAngle);
}

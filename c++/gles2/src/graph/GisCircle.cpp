#include "GisCircle.h"

GisCircle::GisCircle(void)
{
    ;
}

GisCircle::GisCircle(GisPoint pOrig, double r, double startAngle, double spanAngle)
{
    std::vector<GisPoint> points;
    makePoints(points, pOrig, r, startAngle, spanAngle);
    AddPoints(points);
}

GisCircle::GisCircle(GisPoint pOrig, double r)
{
    std::vector<GisPoint> points;
    makePoints(points, pOrig, r, 0, 2 * GIS_PI);
    AddPoints(points);
} 

void GisCircle::makePoints(std::vector<GisPoint> &points, GisPoint pOrig, double r, double startAngle, double spanAngle)
{
    double x = 0;
    double y = 0;
    double angle = 0;
    double endAngle = 0;

    angle = startAngle;

    if(spanAngle > 2 * GIS_PI)
    {
        spanAngle = 2 * GIS_PI;
    }

    endAngle = startAngle + spanAngle;

    while(angle < endAngle)
    {
        x = r * cos(angle);
        y = r * sin(angle);
        angle += GIS_CIRCLE_ANGLE_PER_LINE;
        points.push_back(GisPoint(x, y));
    }
} 

/*
 * TODO: 参数检查
 */
void GisCircle::draw(GisColor c)
{
    GisLines::draw(c, GL_LINE_STRIP);
}


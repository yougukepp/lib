#include "GisArc.h"

GisArc::GisArc(GisPoint pOrig, double r, double startAngle, double spanAngle, GisColor c)
    :GisLines()
{
    std::vector<GisPoint> points;
    makePoints(points, pOrig, r, startAngle, spanAngle);
    AddPoints(points);
    SetColor(c);
}

void GisArc::draw(void)
{
    GisLines::draw(GL_LINE_STRIP);
}

void GisArc::makePoints(std::vector<GisPoint> &points, GisPoint pOrig, 
        double r, double startAngle, double spanAngle)
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


#include "GisOval.h"

GisOval::GisOval(GisPoint pOrig, double a, double b, GisColor c)
    :GisLines()
{
    std::vector<GisPoint> points;
    MakePoints(points, pOrig, a, b, 0, 2 * GIS_PI);
    AddPoints(points);
    SetColor(c);
} 

GisOval::~GisOval(void)
{
    ;
}

void GisOval::Draw(void)
{
    GisPrimitives::Draw(GL_LINE_LOOP);
} 

void GisOval::MakePoints(std::vector<GisPoint> &points, GisPoint pOrig, double a, double b,
        double startAngle, double spanAngle)
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
        x = a * cos(angle);
        y = b * sin(angle);
        angle += GIS_CIRCLE_ANGLE_PER_LINE;
        points.push_back(GisPoint(x, y));
    }
}


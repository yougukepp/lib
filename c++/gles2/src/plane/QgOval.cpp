#include "QgOval.h"

QgOval::QgOval(QgPoint pOrig, double a, double b, QgColor c)
    :QgLines()
{
    std::vector<QgPoint> points;
    MakePoints(points, pOrig, a, b, 0, 2 * QG_PI);
    AddPoints(points);
    SetColor(c);
} 

QgOval::~QgOval(void)
{
    ;
}

void QgOval::Draw(void)
{
    QgPrimitives::Draw(GL_LINE_LOOP);
} 

void QgOval::MakePoints(std::vector<QgPoint> &points, QgPoint pOrig, double a, double b,
        double startAngle, double spanAngle)
{
    double x = 0;
    double y = 0;
    double angle = 0;
    double endAngle = 0;

    angle = startAngle;

    if(spanAngle > 2 * QG_PI)
    {
        spanAngle = 2 * QG_PI;
    }

    endAngle = startAngle + spanAngle;

    while(angle < endAngle)
    {
        x = a * cos(angle);
        y = b * sin(angle);
        angle += QG_CIRCLE_ANGLE_PER_LINE;
        points.push_back(QgPoint(x, y));
    }
}


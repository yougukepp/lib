#include "QgPie.h"

QgPie::QgPie(QgPoint pOrig, double r, double startAngle, double spanAngle, QgColor c)
    :QgLines()
{
    std::vector<QgPoint> points;
    QgCircle::MakePoints(points, pOrig, r, startAngle, spanAngle);
    points.push_back(pOrig);
    AddPoints(points);
    SetColor(c);
} 

QgPie::~QgPie(void)
{
    ;
}

void QgPie::Draw(void)
{
    QgPrimitives::Draw(GL_LINE_LOOP);
}


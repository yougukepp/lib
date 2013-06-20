#include "QgArc.h"

QgArc::QgArc(QgPoint pOrig, double r, double startAngle, double spanAngle, QgColor c)
    :QgLines()
{
    std::vector<QgPoint> points;
    QgCircle::MakePoints(points, pOrig, r, startAngle, spanAngle);
    AddPoints(points);
    SetColor(c);
}

QgArc::~QgArc(void)
{
    ;
}

void QgArc::Draw(void)
{
    QgPrimitives::Draw(GL_LINE_STRIP);
}


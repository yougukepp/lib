#include "QgCircle.h"

QgCircle::QgCircle(QgPoint pOrig, double r, QgColor c)
    :QgOval(pOrig, r, r, c)
{
} 

QgCircle::~QgCircle(void)
{
    ;
}

void QgCircle::Draw(void)
{
    QgPrimitives::Draw(GL_LINE_LOOP);
}

void QgCircle::MakePoints(std::vector<QgPoint> &points, QgPoint pOrig, double r,
        double startAngle, double spanAngle)
{
    QgOval::MakePoints(points, pOrig, r, r, startAngle, spanAngle);
}

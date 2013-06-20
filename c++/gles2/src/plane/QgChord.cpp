#include "QgChord.h"

QgChord::QgChord(QgPoint pOrig, double r, double startAngle, double spanAngle, QgColor c)
    :QgLines()
{
    std::vector<QgPoint> points;
    QgCircle::MakePoints(points, pOrig, r, startAngle, spanAngle);
    AddPoints(points);
    SetColor(c);
}

QgChord::~QgChord(void)
{
    ;
}

void QgChord::Draw(void)
{
    QgPrimitives::Draw(GL_LINE_LOOP);
}


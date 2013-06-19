#include "QgSpritePoint.h"

QgSpritePoint::QgSpritePoint(QgPoint &point, QgColor c, float size)
    : QgPrimitive()
{
    std::vector<QgPoint> points;
    points.push_back(point);

    AddPoints(points);
    SetColor(c);
    m_size = size;
}

void QgSpritePoint::Draw(void)
{
    QgPrimitive::Draw(GL_POINTS);
}

QgSpritePoint::~QgSpritePoint(void)
{
    ;
}


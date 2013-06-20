#include "QgSpritePoint.h"

QgSpritePoint::QgSpritePoint(QgPoint &point, QgColor c, float size)
    : QgPrimitive()
{
    std::vector<QgPoint> points;
    points.push_back(point);

    AddPoints(points);
    SetColor(c);
    setPointSize(size);
}

/*TODO: 某些硬件单点无法绘制 */
void QgSpritePoint::Draw(void)
{
    DrawPrimitive(GL_POINTS);
}

QgSpritePoint::~QgSpritePoint(void)
{
    ;
}


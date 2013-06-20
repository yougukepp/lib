#include "QgSpritePoints.h"

QgSpritePoints::QgSpritePoints(std::vector<QgPoint> &points, QgColor c, float size)
    : QgPrimitive(points, c)
{
    SetPointSize(size);
}

/*TODO: 某些硬件单点无法绘制 */
void QgSpritePoints::Draw(void)
{
    DrawPrimitive(GL_POINTS);
}

QgSpritePoints::~QgSpritePoints(void)
{
    ;
}


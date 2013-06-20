#include "QgLineStrip.h" 

QgLineStrip::QgLineStrip(const std::vector<QgPoint> &points, QgColor c, float width)
    : QgPrimitive(points, c)
{ 
    SetLineWidth(width);
} 

QgLineStrip::QgLineStrip(void)
    : QgPrimitive()
{
}

void QgLineStrip::Draw(void)
{
    QgPrimitive::DrawPrimitive(GL_LINE_STRIP);
}

QgLineStrip::~QgLineStrip(void)
{
    /* 会自动调用基类QgPrimitives析构函数 */
}


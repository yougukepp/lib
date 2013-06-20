#include "QgLine.h" 

QgLine::QgLine(const std::vector<QgPoint> &points, QgColor c, float width)
    : QgPrimitive(points, c)
{ 
    setLineWidth(width);
} 

QgLine::QgLine(void)
    : QgPrimitive()
{
}

void QgLine::Draw(void)
{
    QgPrimitive::DrawPrimitive(GL_LINES);
}

QgLine::~QgLine(void)
{
    /* 会自动调用基类QgPrimitives析构函数 */
}


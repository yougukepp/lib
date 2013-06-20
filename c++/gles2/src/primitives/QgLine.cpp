#include "QgLine.h" 

QgLine::QgLine(const std::vector<QgPoint> &points, QgColor c)
    : QgPrimitive(points, c)
{ 
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


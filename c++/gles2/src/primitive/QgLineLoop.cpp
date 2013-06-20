#include "QgLineLoop.h" 

QgLineLoop::QgLineLoop(const std::vector<QgPoint> &points, QgColor c, float width)
    : QgPrimitive(points, c)
{ 
    SetLineWidth(width);
} 

QgLineLoop::QgLineLoop(void)
    : QgPrimitive()
{
}

void QgLineLoop::Draw(void)
{
    QgPrimitive::DrawPrimitive(GL_LINE_LOOP);
}

QgLineLoop::~QgLineLoop(void)
{
    /* 会自动调用基类QgPrimitives析构函数 */
}


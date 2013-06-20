#include "QgLines.h" 

QgLines::QgLines(const std::vector<QgPoint> &points, QgColor c, float width)
    : QgPrimitive(points, c)
{ 
    SetLineWidth(width);
} 

QgLines::QgLines(void)
    : QgPrimitive()
{
}

void QgLines::Draw(void)
{
    QgPrimitive::DrawPrimitive(GL_LINES);
}

QgLines::~QgLines(void)
{
    /* 会自动调用基类QgPrimitives析构函数 */
}


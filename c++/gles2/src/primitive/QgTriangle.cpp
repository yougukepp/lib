#include "QgTriangle.h" 

QgTriangle::QgTriangle(const std::vector<QgPoint> &points, QgColor c)
    : QgPrimitive(points, c)
{ 
} 

QgTriangle::QgTriangle(void)
    : QgPrimitive()
{
}

void QgTriangle::Draw(void)
{
    QgPrimitive::DrawPrimitive(GL_TRIANGLES);
}

QgTriangle::~QgTriangle(void)
{
    /* 会自动调用基类QgPrimitive析构函数 */
}


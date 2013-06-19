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
    QgPrimitive::Draw(GL_LINES);
}

QgTriangle::~QgTriangle(void)
{
    /* 会自动调用基类QgPrimitive析构函数 */
}


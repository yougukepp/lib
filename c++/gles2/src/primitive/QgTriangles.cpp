#include "QgTriangles.h" 

QgTriangles::QgTriangles(const std::vector<QgPoint> &points, QgColor c)
    : QgPrimitive(points, c)
{ 
} 

QgTriangles::QgTriangles(void)
    : QgPrimitive()
{
}

void QgTriangles::Draw(void)
{
    QgPrimitive::DrawPrimitive(GL_TRIANGLES);
}

QgTriangles::~QgTriangles(void)
{
    /* 会自动调用基类QgPrimitive析构函数 */
}


#include "QgTriangles.h" 

QgTriangles::QgTriangles(const std::vector<QgVertex> &points, QgColor c)
    : QgPrimitive(points, c)
{ 
} 

void QgTriangles::Draw(void)
{
    DrawPrimitive(GL_TRIANGLES);
}


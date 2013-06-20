#include "QgTriangles.h" 

QgTriangles::QgTriangles(const std::vector<QgPoint> &points, QgColor c)
    : QgPrimitive(points, c)
{ 
} 

void QgTriangles::Draw(void)
{
    DrawPrimitive(GL_TRIANGLES);
}


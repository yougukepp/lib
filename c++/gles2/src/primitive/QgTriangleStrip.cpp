#include "QgTriangleStrip.h" 

QgTriangleStrip::QgTriangleStrip(const std::vector<QgVertex> &points, QgColor c)
    : QgPrimitive(points, c)
{ 
} 

void QgTriangleStrip::Draw(void)
{
    DrawPrimitive(GL_TRIANGLE_STRIP);
}


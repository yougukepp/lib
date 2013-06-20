#include "QgTriangleStrip.h" 

QgTriangleStrip::QgTriangleStrip(const std::vector<QgPoint> &points, QgColor c)
    : QgPrimitive(points, c)
{ 
} 

void QgTriangleStrip::Draw(void)
{
    DrawPrimitive(GL_TRIANGLE_STRIP);
}


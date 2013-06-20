#include "QgTriangleFan.h" 

QgTriangleFan::QgTriangleFan(const std::vector<QgPoint> &points, QgColor c)
    : QgPrimitive(points, c)
{ 
} 

void QgTriangleFan::Draw(void)
{
    DrawPrimitive(GL_TRIANGLE_FAN);
}


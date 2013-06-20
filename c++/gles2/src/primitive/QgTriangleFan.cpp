#include "QgTriangleFan.h" 

QgTriangleFan::QgTriangleFan(const std::vector<QgVertex> &points, QgColor c)
    : QgPrimitive(points, c)
{ 
} 

void QgTriangleFan::Draw(void)
{
    DrawPrimitive(GL_TRIANGLE_FAN);
}


#include "QgLineLoop.h" 

QgLineLoop::QgLineLoop(const std::vector<QgPoint> &points, QgColor c, float width)
    : QgBaseLine(points, c, width)
{ 
} 

void QgLineLoop::Draw(void)
{
    DrawPrimitive(GL_LINE_LOOP);
}


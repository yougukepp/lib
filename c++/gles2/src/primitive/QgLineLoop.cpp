#include "QgLineLoop.h" 

QgLineLoop::QgLineLoop(const std::vector<QgVertex> &points, QgColor c, float width)
    : QgBaseLine(points, c, width)
{ 
} 

void QgLineLoop::Draw(void)
{
    DrawPrimitive(GL_LINE_LOOP);
}


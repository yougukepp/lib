#include "QgLines.h" 

QgLines::QgLines(const std::vector<QgVertex> &points, QgColor c, float width)
    : QgBaseLine(points, c, width)
{ 
} 

void QgLines::Draw(void)
{
    DrawPrimitive(GL_LINES);
}


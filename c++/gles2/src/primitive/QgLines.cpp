#include "QgLines.h" 

QgLines::QgLines(const std::vector<QgPoint> &points, QgColor c, float width)
    : QgBaseLine(points, c, width)
{ 
} 

void QgLines::Draw(void)
{
    DrawPrimitive(GL_LINES);
}


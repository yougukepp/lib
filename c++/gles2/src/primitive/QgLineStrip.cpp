#include "QgLineStrip.h" 

QgLineStrip::QgLineStrip(const std::vector<QgVertex> &points, QgColor c, float width)
    : QgBaseLine(points, c, width)
{ 
} 

void QgLineStrip::Draw(void)
{
    DrawPrimitive(GL_LINE_STRIP);
}


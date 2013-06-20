#include "QgLineStrip.h" 

QgLineStrip::QgLineStrip(const std::vector<QgPoint> &points, QgColor c, float width)
    : QgBaseLine(points, c, width)
{ 
} 

void QgLineStrip::Draw(void)
{
    DrawPrimitive(GL_LINE_STRIP);
}


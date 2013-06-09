#include "GisArc.h"

GisArc::GisArc(GisPoint pOrig, double r, double startAngle, double spanAngle)
{
    m_circle = GisCircle(pOrig, r, startAngle, spanAngle);
}

void GisArc::drawLoop(GisColor c)
{
    m_circle.draw(c);
}

void GisArc::draw(GisColor c)
{
    m_circle.drawPart(c);
}


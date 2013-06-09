#ifndef __GIS_ARC_H__
#define __GIS_ARC_H__

#include "GisCircle.h"

class GisArc
{
public:
    GisArc(GisPoint pOrig, double r, double startAngle, double spanAngle); 
    void draw(GisColor c); 
    void drawLoop(GisColor c);

private:
    GisCircle m_circle;
    double m_startAngle;
    double m_spanAngle;
};

#endif


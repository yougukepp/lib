#ifndef __GIS_CIRCLE_H__
#define __GIS_CIRCLE_H__

#include "GisPoint.h"
#include "GisLines.h"

class GisCircle: public GisLines
{
public:
    GisCircle(GisPoint pOrig, double r);
    GisCircle(GisPoint pOrig, double r, double startAngle, double spanAngle);

    GisCircle(void);
    void draw(GisColor c);
    void drawPart(GisColor c);
protected: 
    void makePoints(std::vector<GisPoint> &points, GisPoint pOrig, double r, double startAngle, double spanAngle);

};

#endif


#ifndef __GIS_ARC_H__
#define __GIS_ARC_H__

#include "GisLines.h"

class GisArc: public GisLines
{
public:
    GisArc(GisPoint pOrig, double r, double startAngle, double spanAngle, GisColor c); 
    void draw(bool loop); 
    
    static void makePoints(std::vector<GisPoint> &points, GisPoint pOrig, 
        double r, double startAngle, double spanAngle);

private:

};

#endif


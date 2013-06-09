#ifndef __GIS_CIRCLE_H__
#define __GIS_CIRCLE_H__

#include "GisOval.h"

class GisCircle: public GisOval
{
public:
    GisCircle(GisPoint pOrig, double r, GisColor c);
    void draw(void); 
    
    static void makePoints(std::vector<GisPoint> &points, GisPoint pOrig, double r,
            double startAngle, double spanAngle);
protected: 


};

#endif


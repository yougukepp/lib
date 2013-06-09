#ifndef __GIS_PIE_H__
#define __GIS_PIE_H__

#include "GisLines.h"
#include "GisArc.h"

class GisPie : public GisLines
{
public:
    GisPie(GisPoint pOrig, double r, double startAngle, double spanAngle, GisColor c); 
    void draw(void); 
    
private:

};

#endif


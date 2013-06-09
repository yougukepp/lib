#ifndef __GIS_CIRCLE_H__
#define __GIS_CIRCLE_H__

#include "GisArc.h"

class GisCircle: public GisLines
{
public:
    GisCircle(GisPoint pOrig, double r, GisColor c);
    void draw(void);
protected: 
};

#endif


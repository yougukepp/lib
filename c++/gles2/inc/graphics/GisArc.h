#ifndef __GIS_ARC_H__
#define __GIS_ARC_H__

#include "GisLines.h"
#include "GisCircle.h"

class GisArc: public GisLines
{
public:
    GisArc(GisPoint pOrig, double r, double startAngle, double spanAngle, GisColor c); 
    virtual ~GisArc(void);
    void Draw(void); 

private:

};

#endif


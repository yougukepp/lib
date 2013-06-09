#ifndef __GIS_CHORD_H__
#define __GIS_CHORD_H__

#include "GisLines.h"
#include "GisArc.h"

class GisChord : public GisLines
{
public:
    GisChord(GisPoint pOrig, double r, double startAngle, double spanAngle, GisColor c); 
    void draw(void); 
    
private:

};

#endif


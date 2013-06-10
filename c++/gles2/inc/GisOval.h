#ifndef __GIS_OVAL_H__
#define __GIS_OVAL_H__

#include "GisLines.h"

class GisOval : public GisLines
{
public: 
    GisOval(GisPoint pOrig, double a, double b, GisColor c);
    void Draw(void); 
    
    static void MakePoints(std::vector<GisPoint> &points, GisPoint pOrig, 
            double a, double b, double startAngle, double spanAngle);
    
private:

};

#endif


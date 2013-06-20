#ifndef __QG_ARC_H__
#define __QG_ARC_H__

#include "QgLine.h"
#include "QgCircle.h"

class QgArc: public GisLine
{
public:
    QgArc(GisPoint pOrig, double r, double startAngle, double spanAngle, GisColor c); 
    virtual ~QgArc(void);
    void Draw(void); 

private:

};

#endif


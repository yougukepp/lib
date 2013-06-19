#ifndef __GIS_LINES__
#define __GIS_LINES__

#include "GisPoint.h"
#include "GisColor.h"
#include "GisProgram.h"
#include "GisPrimitives.h"

class GisLines : public GisPrimitives
{
public:
    GisLines(const std::vector<GisPoint> &points, GisColor c);
    virtual void Draw(void);
    virtual ~GisLines(void);

protected: 
    GisLines(void);

private:
};

#endif


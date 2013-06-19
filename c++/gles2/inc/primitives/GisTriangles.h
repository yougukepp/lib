#ifndef __GIS_TRIANGLES__
#define __GIS_TRIANGLES__

#include "GisPoint.h"
#include "GisColor.h"
#include "GisProgram.h"
#include "GisPrimitives.h"

class GisTriangles : public GisPrimitives
{
public:
    GisTriangles(const std::vector<GisPoint> &points, GisColor c);
    virtual void Draw(void);
    virtual ~GisTriangles(void);

protected: 
    GisTriangles(void);

private:
};

#endif


#ifndef __GIS_POLYGOA_H__
#define __GIS_POLYGOA_H__

#include "GisLines.h"

class GisPolygon : public GisLines
{
public:
    GisPolygon(const std::vector<GisPoint> &points, GisColor c);
    void Draw(void);
    virtual ~GisPolygon(void);

protected:
    GisPolygon(void);

private:
};

#endif


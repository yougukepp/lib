#ifndef __GIS_RECT_H__
#define __GIS_RECT_H__

#include "GisPolygon.h"

class GisRect : public GisPolygon
{
public:
    GisRect(const std::vector<GisPoint> &p1);
    void draw(GisColor c);

private:
};

#endif


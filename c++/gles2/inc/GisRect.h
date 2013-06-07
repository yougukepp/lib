#ifndef __GIS_RECT_H__
#define __GIS_RECT_H__

#include "GisPolygon.h"

class GisRect : public GisPolygon
{
public:
    GisRect(const std::vector<GisPoint> &p1);
    draw(GisColor &c);

private:
    GisProgram *m_pProgram;
    std::vector<GisPoint> m_points;
};

#endif


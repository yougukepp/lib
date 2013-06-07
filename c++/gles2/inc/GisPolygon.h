#ifndef __GIS_POLYGOA_H__
#define __GIS_POLYGOA_H__

#include "GisLines.h"

class GisPolygon : public GisLines
{
public:
    GisPolygon(void);
    void draw(std::vector<GisPoint> &points, GisColor &c);

private:
    GisProgram *m_pProgram;
};

#endif


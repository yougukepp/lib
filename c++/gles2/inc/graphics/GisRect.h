#ifndef __GIS_RECT_H__
#define __GIS_RECT_H__

#include "GisPolygon.h"

class GisRect : public GisPolygon
{
public:
    GisRect(float x, float y, float w, float h, GisColor c);

    GisPoint GetOrigin(void);
    float GetWidth(void);
    float GetHeight(void);

private:
    float m_x;
    float m_y;
    float m_w;
    float m_h;
};

#endif


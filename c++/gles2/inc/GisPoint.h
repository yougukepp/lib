#ifndef __GIS_POINT_H__
#define __GIS_POINT_H__

#include "GisHeader.h"

class GisPoint
{
public:
    GisPoint(void);
    GisPoint(float x, float y);
    float GetX(void);
    float GetY(void); 
    
    void print(const char *format);

protected:

private:
    float m_x;
    float m_y;
};

#endif


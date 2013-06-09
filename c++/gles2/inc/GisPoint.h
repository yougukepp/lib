#ifndef __GIS_POINT_H__
#define __GIS_POINT_H__

#include "GisHeader.h"

class GisPoint
{
public:
    GisPoint(void);
    GisPoint(float x, float y);
    GisPoint(float x, float y, float z);
    float GetX(void);
    float GetY(void); 
    float GetZ(void); 
    float GetA(void); 
    
    void print(const char *format);

protected:

private:
    float m_x;
    float m_y;
    float m_z;
    float m_a;
};

#endif


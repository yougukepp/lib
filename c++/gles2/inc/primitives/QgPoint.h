#ifndef __QG_POINT_H__
#define __QG_POINT_H__

#include "QgInnerInterface.h"

class QgPoint
{
public:
    QgPoint(void);
    QgPoint(float x, float y);
    QgPoint(float x, float y, float z);
    float GetX(void);
    float GetY(void); 
    float GetZ(void); 
    float GetA(void); 
    
    void Print(void);

protected:

private:
    float m_x;
    float m_y;
    float m_z;
    float m_a;
};

#endif


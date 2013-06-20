#ifndef __QG_VERTEX_H__
#define __QG_VERTEX_H__

#include "QgInnerInterface.h"

class QgVertex
{
public:
    QgVertex(void);
    QgVertex(float x, float y);
    QgVertex(float x, float y, float z);
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


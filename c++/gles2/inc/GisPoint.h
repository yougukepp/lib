#ifndef __GIS_POINT_H__
#define __GIS_POINT_H__

class GisPoint
{
public:
    GisPoint(float x, float y);
    float GetX(void);
    float GetY(void);

protected:

private:
    float m_x;
    float m_y;
};

#endif


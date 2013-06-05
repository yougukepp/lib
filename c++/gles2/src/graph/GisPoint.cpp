#include "GisPoint.h"

GisPoint::GisPoint(float x, float y)
{
    m_x = x;
    m_y = y;
} 

float GisPoint::GetX(void)
{
    return m_x;
}

float GisPoint::GetY(void)
{
    return m_y;
}


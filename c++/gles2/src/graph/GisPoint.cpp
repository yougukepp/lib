#include "GisPoint.h"

GisPoint::GisPoint(void)
{
    /* 使用OpenGL 归一化坐标 */
    m_x = -1.0f;
    m_y = -1.0f;
}

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

void GisPoint::print(const char *format)
{
    if(NULL == format)
    {
        format = "x:%f,y:%f\n";
    }

    printf(format, GetX(), GetY());
    fflush(stdout);
}

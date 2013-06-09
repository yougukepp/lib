#include "GisPoint.h"

GisPoint::GisPoint(void)
{
    /* 使用OpenGL 归一化坐标 */
    m_x = 0.0f;
    m_y = 0.0f;
    m_z = 0.0f;
    m_a = 1.0f;
}

GisPoint::GisPoint(float x, float y)
{
    m_x = x;
    m_y = y;
    m_z = 0.0f;
    m_a = 1.0f;
}

GisPoint::GisPoint(float x, float y, float z)
{
    m_x = x;
    m_y = y;
    m_z = z;
    m_a = 1.0f;
}

float GisPoint::GetX(void)
{
    return m_x;
}

float GisPoint::GetY(void)
{
    return m_y;
}

float GisPoint::GetZ(void)
{
    return m_z;
}

float GisPoint::GetA(void)
{
    return m_a;
}

void GisPoint::print(const char *format)
{
    if(NULL == format)
    {
        format = "x:%f,y:%f,z:%f,a:%f\n";
    }

    printf(format, GetX(), GetY(), GetZ(), GetA());
    fflush(stdout);
}

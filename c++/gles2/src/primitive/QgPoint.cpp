#include "QgPoint.h"

QgPoint::QgPoint(void)
{
    /* 使用OpenGL 归一化坐标 */
    m_x = 0.0f;
    m_y = 0.0f;
    m_z = 0.0f;
    m_a = 1.0f;
}

QgPoint::QgPoint(float x, float y)
{
    m_x = x;
    m_y = y;
    m_z = 0.0f;
    m_a = 1.0f;
}

QgPoint::QgPoint(float x, float y, float z)
{
    m_x = x;
    m_y = y;
    m_z = z;
    m_a = 1.0f;
}

float QgPoint::GetX(void)
{
    return m_x;
}

float QgPoint::GetY(void)
{
    return m_y;
}

float QgPoint::GetZ(void)
{
    return m_z;
}

float QgPoint::GetA(void)
{
    return m_a;
}

void QgPoint::Print(void)
{
    const char *format = NULL;
    format = "x:%f,y:%f,z:%f,a:%f\n";

    printf(format, GetX(), GetY(), GetZ(), GetA());
    fflush(stdout);
}

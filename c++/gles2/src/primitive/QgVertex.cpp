#include "QgVertex.h"

QgVertex::QgVertex(void)
{
    /* 使用OpenGL 归一化坐标 */
    m_x = 0.0f;
    m_y = 0.0f;
    m_z = 0.0f;
    m_a = 1.0f;
}

QgVertex::QgVertex(float x, float y)
{
    m_x = x;
    m_y = y;
    m_z = 0.0f;
    m_a = 1.0f;
}

QgVertex::QgVertex(float x, float y, float z)
{
    m_x = x;
    m_y = y;
    m_z = z;
    m_a = 1.0f;
}

float QgVertex::GetX(void)
{
    return m_x;
}

float QgVertex::GetY(void)
{
    return m_y;
}

float QgVertex::GetZ(void)
{
    return m_z;
}

float QgVertex::GetA(void)
{
    return m_a;
}

void QgVertex::Print(void)
{
    const char *format = NULL;
    format = "x:%f,y:%f,z:%f,a:%f\n";

    printf(format, GetX(), GetY(), GetZ(), GetA());
    fflush(stdout);
}

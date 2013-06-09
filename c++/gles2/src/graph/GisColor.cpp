#include "GisColor.h"

GisColor::GisColor(void)
{
    /* 默认使用白色 */
    m_r = 1.0f;
    m_g = 1.0f;
    m_b = 1.0f;
}

GisColor::GisColor(float r, float g, float b)
{
    m_r = r;
    m_g = g;
    m_b = b;
}

float GisColor::GetR(void)
{
    return m_r;
}

float GisColor::GetG(void)
{
    return m_g;
}

float GisColor::GetB(void)
{
    return m_b;
}


#include "GisColor.h"

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


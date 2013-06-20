#include "QgColor.h"

QgColor::QgColor(void)
{
    /* 默认使用白色 */
    m_r = 1.0f;
    m_g = 1.0f;
    m_b = 1.0f;

    m_a = 1.0f;
}

QgColor::QgColor(float r, float g, float b)
{
    m_r = r;
    m_g = g;
    m_b = b;

    m_a = 1.0f;
}

float QgColor::GetR(void)
{
    return m_r;
}

float QgColor::GetG(void)
{
    return m_g;
}

float QgColor::GetB(void)
{
    return m_b;
}

float QgColor::GetA(void)
{
    return m_a;
}


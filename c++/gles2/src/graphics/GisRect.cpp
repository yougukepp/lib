#include "GisRect.h"

GisRect::GisRect(float x, float y, float w, float h, GisColor c)
    :GisPolygon()
{
    m_x = x;
    m_y = y;
    m_w = w;
    m_h = h;

    GisPoint leftTop(x, y);
    GisPoint rightTop(x + w, y);
    GisPoint leftBottom(x, y - h);
    GisPoint rightBootom(x + w, y - h);
    std::vector<GisPoint> points;
    points.push_back(leftTop);
    points.push_back(rightTop);
    points.push_back(rightBootom);
    points.push_back(leftBottom);

    AddPoints(points);
    SetColor(c);
} 

GisPoint GisRect::GetOrigin(void)
{
    GisPoint origin(m_x, m_y);
    return origin;
} 

float GisRect::GetWidth(void)
{
    return m_w;
}

float GisRect::GetHeight(void)
{
    return m_h;
}


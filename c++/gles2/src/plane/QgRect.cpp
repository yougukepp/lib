#include "QgRect.h"

QgRect::QgRect(float x, float y, float w, float h, QgColor c)
    :QgPolygon()
{
    m_x = x;
    m_y = y;
    m_w = w;
    m_h = h;

    QgPoint leftTop(x, y);
    QgPoint rightTop(x + w, y);
    QgPoint leftBottom(x, y - h);
    QgPoint rightBootom(x + w, y - h);
    std::vector<QgPoint> points;
    points.push_back(leftTop);
    points.push_back(rightTop);
    points.push_back(rightBootom);
    points.push_back(leftBottom);

    AddPoints(points);
    SetColor(c);
} 

QgPoint QgRect::GetOrigin(void)
{
    QgPoint origin(m_x, m_y);
    return origin;
} 

float QgRect::GetWidth(void)
{
    return m_w;
}

float QgRect::GetHeight(void)
{
    return m_h;
}


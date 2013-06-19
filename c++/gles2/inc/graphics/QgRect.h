#ifndef __QG_RECT_H__
#define __QG_RECT_H__

#include "QgPolygon.h"

class QgRect : public QgPolygon
{
public:
    QgRect(float x, float y, float w, float h, QgColor c);

    QgPoint GetOrigin(void);
    float GetWidth(void);
    float GetHeight(void);

private:
    float m_x;
    float m_y;
    float m_w;
    float m_h;
};

#endif


#ifndef __QG_POLYGON_H__
#define __QG_POLYGON_H__

#include "QgLineLoop.h"
#include "QgTriangleStrip.h"

class QgPolygon
{
public:
    QgPolygon(const std::vector<QgPoint> &points, QgColor c);
    void Draw(void);

protected:

private:

};

#endif


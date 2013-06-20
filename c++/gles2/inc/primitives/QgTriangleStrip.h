#ifndef __QG_TRIANGLE_STRIP_H__
#define __QG_TRIANGLE_STRIP_H__

#include "QgPoint.h"
#include "QgColor.h"
#include "QgIDrawable.h"
#include "QgPrimitive.h"

class QgTriangleStrip : public QgPrimitive, public QgIDrawable
{
public:
    QgTriangleStrip(const std::vector<QgPoint> &points, QgColor c);
    void Draw(void);

protected: 

private:
};

#endif


#ifndef __QG_TRIANGLE_FAN_H__
#define __QG_TRIANGLE_FAN_H__

#include "QgVertex.h"
#include "QgColor.h"
#include "QgIDrawable.h"
#include "QgPrimitive.h"

class QgTriangleFan : public QgPrimitive, public QgIDrawable
{
public:
    QgTriangleFan(const std::vector<QgVertex> &points, QgColor c);
    void Draw(void);

protected: 

private:
};

#endif


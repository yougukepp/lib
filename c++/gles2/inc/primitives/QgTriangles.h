#ifndef __QG_TRIANGLES_H__
#define __QG_TRIANGLES_H__

#include "QgVertex.h"
#include "QgColor.h"
#include "QgIDrawable.h"
#include "QgPrimitive.h"

class QgTriangles : public QgPrimitive, public QgIDrawable
{
public:
    QgTriangles(const std::vector<QgVertex> &points, QgColor c);
    void Draw(void);

protected: 

private:
};

#endif


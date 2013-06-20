#ifndef __QG_TRIANGLES_H__
#define __QG_TRIANGLES_H__

#include "QgPoint.h"
#include "QgColor.h"
#include "QgProgram.h"
#include "QgPrimitive.h"

class QgTriangles : public QgPrimitive
{
public:
    QgTriangles(const std::vector<QgPoint> &points, QgColor c);
    virtual void Draw(void);
    virtual ~QgTriangles(void);

protected: 
    QgTriangles(void);

private:
};

#endif


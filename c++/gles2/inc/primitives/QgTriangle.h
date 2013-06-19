#ifndef __QG_TRIANGLE_H__
#define __QG_TRIANGLE_H__

#include "QgPoint.h"
#include "QgColor.h"
#include "QgProgram.h"
#include "QgPrimitive.h"

class QgTriangle : public QgPrimitive
{
public:
    QgTriangle(const std::vector<QgPoint> &points, QgColor c);
    virtual void Draw(void);
    virtual ~QgTriangle(void);

protected: 
    QgTriangle(void);

private:
};

#endif


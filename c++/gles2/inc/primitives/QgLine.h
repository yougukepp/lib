#ifndef __GIS_LINES__
#define __GIS_LINES__

#include "QgPoint.h"
#include "QgColor.h"
#include "QgProgram.h"
#include "QgPrimitive.h"

class QgLine : public QgPrimitive
{
public:
    QgLine(const std::vector<QgPoint> &points, QgColor c);
    virtual void Draw(void);
    virtual ~QgLine(void);

protected: 
    QgLine(void);

private:
};

#endif


#ifndef __GIS_LINES__
#define __GIS_LINES__

#include "QgPoint.h"
#include "QgColor.h"
#include "QgProgram.h"
#include "QgPrimitive.h"

class QgLines : public QgPrimitive
{
public:
    QgLines(const std::vector<QgPoint> &points, QgColor c, float width);
    void Draw(void);
    ~QgLines(void);

protected: 
    QgLines(void);

private:
};

#endif


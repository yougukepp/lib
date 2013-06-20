#ifndef __QG_LINE_LOOP_H__
#define __QG_LINE_LOOP_H__

#include "QgPoint.h"
#include "QgColor.h"
#include "QgPrimitive.h"

class QgLineLoop : public QgPrimitive
{
public:
    QgLineLoop(const std::vector<QgPoint> &points, QgColor c, float width);
    void Draw(void);
    ~QgLineLoop(void);

protected: 
    QgLineLoop(void);

private:
};

#endif


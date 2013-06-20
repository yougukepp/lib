#ifndef __QG_LINE_STRIP_H__
#define __QG_LINE_STRIP_H__

#include "QgPoint.h"
#include "QgColor.h"
#include "QgPrimitive.h"

class QgLineStrip : public QgPrimitive
{
public:
    QgLineStrip(const std::vector<QgPoint> &points, QgColor c, float width);
    void Draw(void);
    ~QgLineStrip(void);

protected: 
    QgLineStrip(void);

private:
};

#endif


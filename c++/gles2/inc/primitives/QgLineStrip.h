#ifndef __QG_LINE_STRIP_H__
#define __QG_LINE_STRIP_H__

#include "QgPoint.h"
#include "QgColor.h"
#include "QgBaseLine.h"

class QgLineStrip : public QgBaseLine
{
public:
    QgLineStrip(const std::vector<QgPoint> &points, QgColor c, float width);
    void Draw(void);

protected: 

private:
};

#endif


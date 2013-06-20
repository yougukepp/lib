#ifndef __QG_LINE_STRIP_H__
#define __QG_LINE_STRIP_H__

#include "QgVertex.h"
#include "QgColor.h"
#include "QgBaseLine.h"

class QgLineStrip : public QgBaseLine
{
public:
    QgLineStrip(const std::vector<QgVertex> &points, QgColor c, float width);
    void Draw(void);

protected: 

private:
};

#endif


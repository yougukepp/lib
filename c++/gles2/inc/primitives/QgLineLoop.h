#ifndef __QG_LINE_LOOP_H__
#define __QG_LINE_LOOP_H__

#include "QgVertex.h"
#include "QgColor.h"
#include "QgBaseLine.h"

class QgLineLoop : public QgBaseLine
{
public:
    QgLineLoop(const std::vector<QgVertex> &points, QgColor c, float width);
    void Draw(void);

protected: 

private:
};

#endif


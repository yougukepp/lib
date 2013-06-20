#ifndef __QG_LINES_H__
#define __QG_LINES_H__

#include "QgVertex.h"
#include "QgColor.h"
#include "QgBaseLine.h"

class QgLines : public QgBaseLine
{
public:
    QgLines(const std::vector<QgVertex> &points, QgColor c, float width);
    void Draw(void);

protected: 

private:
};

#endif


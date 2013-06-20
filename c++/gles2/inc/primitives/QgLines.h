#ifndef __QG_LINES_H__
#define __QG_LINES_H__

#include "QgPoint.h"
#include "QgColor.h"
#include "QgBaseLine.h"

class QgLines : public QgBaseLine
{
public:
    QgLines(const std::vector<QgPoint> &points, QgColor c, float width);
    void Draw(void);

protected: 

private:
};

#endif


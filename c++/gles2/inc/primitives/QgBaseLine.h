#ifndef __QG_BASE_LINE_H__
#define __QG_BASE_LINE_H__

#include "QgInnerInterface.h"

class QgBaseLine : public QgPrimitive, public QgIDrawable
{
protected: 
    QgBaseLine(const std::vector<QgVertex> &points, QgColor c, float width);
private:
};

#endif


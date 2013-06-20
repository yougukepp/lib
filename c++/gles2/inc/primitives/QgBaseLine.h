#ifndef __QG_BASE_LINE_H__
#define __QG_BASE_LINE_H__

#include "QgPoint.h"
#include "QgColor.h"
#include "QgIDrawable.h"
#include "QgPrimitive.h"

class QgBaseLine : public QgPrimitive, public QgIDrawable
{
protected: 
    QgBaseLine(const std::vector<QgPoint> &points, QgColor c, float width);
private:
};

#endif


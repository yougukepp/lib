#ifndef __QG_LINES_H__
#define __QG_LINES_H__

#include "QgPoint.h"
#include "QgColor.h"
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


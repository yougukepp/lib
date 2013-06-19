#ifndef __QG_POLYGOA_H__
#define __QG_POLYGOA_H__

#include "QgLine.h"

class QgPolygon : public QgLine
{
public:
    QgPolygon(const std::vector<QgPoint> &points, QgColor c);
    void Draw(void);
    virtual ~QgPolygon(void);

protected:
    QgPolygon(void);

private:
};

#endif


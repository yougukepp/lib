#ifndef __QG_ARC_H__
#define __QG_ARC_H__

#include "QgLine.h"
#include "QgCircle.h"

class QgArc: public QgLine
{
public:
    QgArc(QgPoint pOrig, double r, double startAngle, double spanAngle, QgColor c); 
    virtual ~QgArc(void);
    void Draw(void); 

private:

};

#endif


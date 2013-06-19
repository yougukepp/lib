#ifndef __QG_PIE_H__
#define __QG_PIE_H__

#include "QgLine.h"
#include "QgArc.h"

class QgPie : public QgLine
{
public:
    QgPie(QgPoint pOrig, double r, double startAngle, double spanAngle, QgColor c); 
    virtual ~QgPie(void);
    void Draw(void); 
    
private:

};

#endif


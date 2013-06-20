#ifndef __QG_CIRCLE_H__
#define __QG_CIRCLE_H__

#include "QgOval.h"

class QgCircle: public GisOval
{
public:
    QgCircle(QgPoint pOrig, double r, QgColor c);
    virtual ~QgCircle(void);
    void Draw(void); 
    
    static void MakePoints(std::vector<QgPoint> &points, QgPoint pOrig, double r,
            double startAngle, double spanAngle);
protected: 


};

#endif


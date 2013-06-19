#ifndef __QG_OVAL_H__
#define __QG_OVAL_H__

#include "QgLine.h"

class QgGisOval : public QgLine
{
public: 
    QgOval(QgPoint pOrig, double a, double b, QgColor c);
    virtual ~QgOval(void);
    void Draw(void); 
    
    static void MakePoints(std::vector<QgPoint> &points, QgPoint pOrig, 
            double a, double b, double startAngle, double spanAngle);
    
private:

};

#endif


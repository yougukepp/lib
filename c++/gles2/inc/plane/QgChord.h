#ifndef __QG_CHORD_H__
#define __QG_CHORD_H__

#include "QgLine.h"
#include "QgArc.h"

class QgChord : public QgLines
{
public:
    QgChord(QgPoint pOrig, double r, double startAngle, double spanAngle, QgColor c); 
    virtual ~QgChord(void);
    void Draw(void); 
    
private:

};

#endif


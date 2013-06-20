#ifndef __QG_I_DRAWABLE_H__
#define __QG_I_DRAWABLE_H__

class QgIDrawable
{
public:
    virtual void Draw(void) = 0;

protected:
    QgIDrawable(void){;}
    virtual ~QgIDrawable(void){;}
};

#endif


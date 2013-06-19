#ifndef __QG_I_DRAWABLE_H__
#define __QG_I_DRAWABLE_H__

class QgIDrawable
{
public:
    QgIDrawable(void){;}
    virtual ~QgIDrawable(void){;}

    virtual void Draw(void) = 0;
};

#endif


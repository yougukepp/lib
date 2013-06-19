#ifndef __QG_SPRITE_POINT_H__
#define __QG_SPRITE_POINT_H__

#include "QgPoint.h"
#include "QgColor.h"
#include "QgPrimitive.h"
#include "QgIDrawable.h"

class QgSpritePoint : public QgPrimitive
{
public:
    QgSpritePoint(QgPoint &points, QgColor c, float size);
    void Draw(void);
    ~QgSpritePoint(void);

protected: 

private:
    float m_size;
};

#endif


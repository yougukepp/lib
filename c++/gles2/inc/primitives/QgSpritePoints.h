#ifndef __QG_SPRITE_POINTS_H__
#define __QG_SPRITE_POINTS_H__

#include "QgVertex.h"
#include "QgColor.h"
#include "QgPrimitive.h"
#include "QgIDrawable.h"

class QgSpritePoints : public QgPrimitive, public QgIDrawable
{
public:
    QgSpritePoints(std::vector<QgVertex> &points, QgColor c, float size); 
    void Draw(void);

protected: 

private:
    float m_size;
};

#endif


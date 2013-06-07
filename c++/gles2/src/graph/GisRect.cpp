#include "GisRect.h"

GisRect::GisRect(const std::vector<GisPoint> &points)
    :GisPolygon(points)
{
#if 0
    /*TODO: 参数检查
     * 1、四个点
     * 2、邻边垂直
     * */
#endif
}

void GisRect::draw(GisColor c)
{
    GisPolygon::draw(c);
}


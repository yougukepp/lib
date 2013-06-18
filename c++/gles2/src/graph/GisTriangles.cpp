#include "GisTriangles.h" 

GisTriangles::GisTriangles(const std::vector<GisPoint> &points, GisColor c)
    : GisPrimitives(points, c)
{ 
} 

GisTriangles::GisTriangles(void)
    : GisPrimitives()
{
}

void GisTriangles::Draw(void)
{
    GisPrimitives::Draw(GL_LINES);
}

GisTriangles::~GisTriangles(void)
{
    /* 会自动调用基类GisPrimitives析构函数 */
}


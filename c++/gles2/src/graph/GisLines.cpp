#include "GisLines.h" 

GisLines::GisLines(const std::vector<GisPoint> &points, GisColor c)
    : GisPrimitives(points, c)
{ 
} 

GisLines::GisLines(void)
    : GisPrimitives()
{
}

void GisLines::Draw(void)
{
    GisPrimitives::Draw(GL_LINES);
}

GisLines::~GisLines(void)
{
    /* 会自动调用基类GisPrimitives析构函数 */
}


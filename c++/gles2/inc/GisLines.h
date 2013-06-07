#ifndef __GIS_LINES__
#define __GIS_LINES__

#include "GisPoint.h"
#include "GisColor.h"
#include "GisProgram.h"

class GisLines
{
public:
    GisLines(const std::vector<GisPoint> &points);
    void draw(GisColor &c);

protected: 
    void draw(GisColor &c, GLenum drawType);
    void setVertexShader(const char *pFileName);
    void setFragmentShader(const char *pFileName); 
    void Link(void);

private:
    GisProgram *m_pProgram;
    std::vector<GisPoint> m_points;
};

#endif


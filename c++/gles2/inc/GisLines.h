#ifndef __GIS_LINES__
#define __GIS_LINES__

#include "GisPoint.h"
#include "GisColor.h"
#include "GisProgram.h"

class GisLines
{
public:
    GisLines(void);
    void draw(std::vector<GisPoint> &points, GisColor &c);

protected: 
    void draw(std::vector<GisPoint> &points, GisColor &c, GLenum drawType);
    void setVertexShader(const char *pFileName);
    void setFragmentShader(const char *pFileName); 
    void Link(void);

private:
    GisProgram *m_pProgram;
};

#endif


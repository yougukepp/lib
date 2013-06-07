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
    GisLines(void);
    void AddPoints(const std::vector<GisPoint> &points);
    void draw(GisColor &c, GLenum drawType);
    void setVertexShader(const char *pFileName);
    void setFragmentShader(const char *pFileName); 
    void Link(void); 
    void CreatAndLinkProgram(const char *vShaderFileName,  const char *fShaderFileName);

private:
    GisProgram *m_pProgram;
    std::vector<GisPoint> m_points;
};

#endif


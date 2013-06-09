#ifndef __GIS_LINES__
#define __GIS_LINES__

#include "GisPoint.h"
#include "GisColor.h"
#include "GisProgram.h"

class GisLines
{
public:
    GisLines(const std::vector<GisPoint> &points, GisColor c);
    virtual void draw(void);

protected: 
    GisLines(void);
    void draw(GLenum drawType);
    void AddPoints(const std::vector<GisPoint> &points);
    void SetColor(GisColor c);
    void setVertexShader(const char *pFileName);
    void setFragmentShader(const char *pFileName); 
    void Link(void); 
    void CreatAndLinkProgram(const char *vShaderFileName,  const char *fShaderFileName);

private:
    GisColor m_c;
    GisProgram *m_pProgram;
    std::vector<GisPoint> m_points;
};

#endif


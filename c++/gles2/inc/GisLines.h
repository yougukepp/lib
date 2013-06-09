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
    void SetGLPosBuf(void);
    void SetGLColorBuf(void);
    void Translate(int x, int y, int z);
    virtual ~GisLines(void);

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
    static const int m_cPosPerVertex = 4;
    static const int m_cColorPerVertex = 4;

    GisColor m_c;
    std::vector<GisPoint> m_points;

    GisProgram *m_pProgram;
    float *m_pPosBuf;
    float *m_pColorBuf;
    float m_matrix[4][4];
};

#endif


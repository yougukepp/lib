#ifndef __GIS_PRIMITIVES__
#define __GIS_PRIMITIVES__

#include "GisPoint.h"
#include "GisColor.h"
#include "GisProgram.h"

class GisPrimitives
{
public:
    GisPrimitives(const std::vector<GisPoint> &points, GisColor c);
    virtual void Draw(void) = 0;
    void Translate(float x, float y, float z);
    void Scale(float x, float y, float z);
    void Rotate(float angle, char axis);
    virtual ~GisPrimitives(void);

protected: 
    GisPrimitives(void);
    void Draw(GLenum drawType);
    void AddPoints(const std::vector<GisPoint> &points);
    void SetColor(GisColor c);

private:
    void DrawTriangles(GLenum drawType);
    void DrawLines(GLenum drawType);
    void SetGLPosBuf(void);
    void SetGLColorBuf(void);
    void CreatAndLinkProgram(const char *vShaderFileName,  const char *fShaderFileName);
    void InitMatrix(void);

    static const int m_cPosPerVertex = 4;
    static const int m_cColorPerVertex = 4;

    GisColor m_c;
    std::vector<GisPoint> m_points;

    GisProgram *m_pProgram;
    float *m_pPosBuf;
    float *m_pColorBuf;
    float *m_arMatrix;
};

#endif


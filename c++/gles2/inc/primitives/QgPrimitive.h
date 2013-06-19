#ifndef __QG_PRIMITIVES__
#define __QG_PRIMITIVES__

#include "QgPoint.h"
#include "QgColor.h"
#include "QgProgram.h"

class QgPrimitive
{
public:
    QgPrimitive(const std::vector<QgPoint> &points, QgColor c);
    virtual void Draw(void) = 0;
    void Translate(float x, float y, float z);
    void Scale(float x, float y, float z);
    void Rotate(float angle, char axis);
    virtual ~QgPrimitive(void);

protected: 
    QgPrimitive(void);
    void Draw(GLenum drawType);
    void AddPoints(const std::vector<QgPoint> &points);
    void SetColor(QgColor c);

private:
    void DrawTriangles(GLenum drawType);
    void DrawLines(GLenum drawType);
    void SetGLPosBuf(void);
    void SetGLColorBuf(void);
    void CreatAndLinkProgram(const char *vShaderFileName,  const char *fShaderFileName);
    void InitMatrix(void);

    static const int m_cPosPerVertex = 4;
    static const int m_cColorPerVertex = 4;

    QgColor m_c;
    std::vector<QgPoint> m_points;

    QgProgram *m_pProgram;
    float *m_pPosBuf;
    float *m_pColorBuf;
    float *m_arMatrix;
};

#endif


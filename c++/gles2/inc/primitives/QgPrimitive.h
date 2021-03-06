#ifndef __QG_PRIMITIVE_H__
#define __QG_PRIMITIVE_H__

#include "QgInnerInterface.h"

class QgProgram;
class QgVertex;
class QgPrimitive
{
public:
    QgPrimitive(const std::vector<QgVertex> &points, QgColor c);
    void Translate(float x, float y, float z);
    void Scale(float x, float y, float z);
    void Rotate(float angle, char axis);
    ~QgPrimitive(void);                         /* TODO:如何避免内存泄漏 */

protected: 
    QgPrimitive(void);
    void DrawPrimitive(GLenum drawType);
    void AddPoints(const std::vector<QgVertex> &points);
    void SetColor(QgColor c); 
    void SetPointSize(float size);
    void SetLineWidth(float width);

private:
    void SetGLPosBuf(void);
    void SetGLColorBuf(void);
    void CreatAndLinkProgram(const char *vShaderFileName,  const char *fShaderFileName);
    void InitMatrix(void);

    static const int m_cPosPerVertex = 4;
    static const int m_cColorPerVertex = 4;

    QgColor m_c;
    float m_pointSize;
    float m_lineWidth;
    std::vector<QgVertex> m_points;

    QgProgram *m_pProgram;
    float *m_pPosBuf;
    float *m_pColorBuf;
    float *m_arMatrix;
};

#endif


#include "GisLines.h"

GisLines::GisLines(const std::vector<GisPoint> &points)
{ 
    m_pProgram = new GisProgram();
    setVertexShader("./glsl/LinesVertex.glsl");
    setFragmentShader("./glsl/LinesFragment.glsl");
    Link();

    int iMax = 0;
    iMax = points.size();
    for(int i=0; i<iMax; i++)
    {
        m_points.push_back(points[i]);
    }
} 

void GisLines::setVertexShader(const char *pFileName)
{
    m_pProgram->setVertexShader(pFileName);
}

void GisLines::setFragmentShader(const char *pFileName)
{
    m_pProgram->setFragmentShader(pFileName);
}

void GisLines::Link()
{
    m_pProgram->Link();
}
/*
 * TODO: 参数检查
 * */
void GisLines::draw(GisColor &c)
{
    draw(c, GL_LINES);
}

/*
 * TODO: 限定参数不可修改
 * */
void GisLines::draw(GisColor &c, GLenum drawType)
{
    const int cCoordsPerVertex = 2;        

    int i = 0;
    int j = 0;
    int iMax = 0;
    int posHandle = 0;
    float *pVertexBuf = NULL;
    float *pColorBuf = NULL;

    iMax = m_points.size();
    pVertexBuf = (float *)malloc(2 * iMax * sizeof(float));
    j = 0;
    for(i=0;i<iMax;i++)
    {
        pVertexBuf[j++] = m_points[i].GetX();
        pVertexBuf[j++] = m_points[i].GetY();
    }

    pColorBuf = (float *)malloc(4 * sizeof(float));
    pColorBuf[0] = c.GetR();
    pColorBuf[1] = c.GetG();
    pColorBuf[2] = c.GetB();
    pColorBuf[3] = 1.0f;

    m_pProgram->Use();
    m_pProgram->BindUniform4fv("vColor", pColorBuf);

    posHandle = m_pProgram->GetAttribLocation("vPosition");
    glEnableVertexAttribArray(posHandle);        
    glVertexAttribPointer(posHandle, cCoordsPerVertex,
            GL_FLOAT, false,
            0, pVertexBuf);
    glDrawArrays(drawType, 0, iMax);

    glDisableVertexAttribArray(posHandle);

    /*TODO: 调查释放内存时机 */
    //free(pVertexBuf);
    //free(pColorBuf);
}


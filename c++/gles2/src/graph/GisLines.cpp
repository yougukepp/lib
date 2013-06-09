#include "GisLines.h" 

GisLines::GisLines(void)
{
    GisColor c;
    SetColor(c);

    std::vector<GisPoint> points;
    points.clear();
    AddPoints(points);

    InitMatrix();

    CreatAndLinkProgram("./glsl/LinesVertex.glsl", "./glsl/LinesFragment.glsl");
}

GisLines::GisLines(const std::vector<GisPoint> &points, GisColor c)
{ 
    AddPoints(points);

    SetColor(c);

    InitMatrix();

    CreatAndLinkProgram("./glsl/LinesVertex.glsl", "./glsl/LinesFragment.glsl");
} 

void GisLines::SetColor(GisColor c)
{
    m_c = c;
    SetGLColorBuf();
}

void GisLines::CreatAndLinkProgram(const char *vShaderFileName,  const char *fShaderFileName)
{
    m_pProgram = new GisProgram();
    setVertexShader(vShaderFileName);
    setFragmentShader(fShaderFileName);
    Link();
}

void GisLines::AddPoints(const std::vector<GisPoint> &points)
{
    int iMax = 0;
    iMax = points.size();
    for(int i=0; i<iMax; i++)
    {
        m_points.push_back(points[i]);
    } 
    
    SetGLPosBuf();
}

void GisLines::InitMatrix(void)
{
    m_arMatrix = (float *)malloc(m_cPosPerVertex * m_cPosPerVertex * sizeof(float));
    assert(NULL != m_arMatrix);

    m_arMatrix[0] = 1.0f;
    m_arMatrix[1] = 0.0f;
    m_arMatrix[2] = 0.0f;
    m_arMatrix[3] = 0.0f;

    m_arMatrix[4] = 0.0f;
    m_arMatrix[5] = 1.0f;
    m_arMatrix[6] = 0.0f;
    m_arMatrix[7] = 0.0f;

    m_arMatrix[8] = 0.0f;
    m_arMatrix[9] = 0.0f;
    m_arMatrix[10] = 1.0f;
    m_arMatrix[11] = 0.0f;

    m_arMatrix[12] = 0.0f;
    m_arMatrix[13] = 0.0f;
    m_arMatrix[14] = 0.0f;
    m_arMatrix[15] = 1.0f;
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

void GisLines::draw(void)
{
    draw(GL_LINES);
}

void GisLines::Translate(float x, float y, float z)
{
    m_arMatrix[3] -= x;
    m_arMatrix[7] -= y;
    m_arMatrix[11] -= z;

    std::min(m_arMatrix[3], 1.0f);
    std::min(m_arMatrix[7], 1.0f);
    std::min(m_arMatrix[11], 1.0f);
}

void GisLines::draw(GLenum drawType)
{
    int posHandle = 0;
    int pointsNums = 0;
    
    pointsNums = m_points.size();

    m_pProgram->Use();
    m_pProgram->BindUniformMatrix4fv("uMatrix", m_arMatrix);
    m_pProgram->BindUniform4fv("uColor", m_pColorBuf);

    posHandle = m_pProgram->GetAttribLocation("vPosition");
    glEnableVertexAttribArray(posHandle);        
    glVertexAttribPointer(posHandle, m_cPosPerVertex,
            GL_FLOAT, false,
            0, m_pPosBuf);
    glDrawArrays(drawType, 0, pointsNums);

    glDisableVertexAttribArray(posHandle);
} 

void GisLines::SetGLPosBuf(void)
{
    int i = 0;
    int j = 0;
    int iMax = 0;

    iMax = m_points.size();
    /*TODO: 使用remalloc 替换*/
    m_pPosBuf = (float *)malloc(m_cPosPerVertex * iMax * sizeof(float));
    assert(NULL != m_pPosBuf);

#ifdef __DEBUG_GIS_TRACE_DRAWED_POINTS__
    printf("GisLines:\n");
#endif
    for(i=0;i<iMax;i++)
    {
        m_pPosBuf[j++] = m_points[i].GetX();
        m_pPosBuf[j++] = m_points[i].GetY(); 
        m_pPosBuf[j++] = m_points[i].GetZ(); 
        m_pPosBuf[j++] = m_points[i].GetA(); 
#ifdef __DEBUG_GIS_TRACE_DRAWED_POINTS__
        printf("point %d:", i);
        m_points[i].print(NULL);
        fflush(stdout);
#endif
    }

}

void GisLines::SetGLColorBuf(void)
{
    m_pColorBuf = (float *)malloc(m_cColorPerVertex * sizeof(float));
    assert(NULL != m_pColorBuf);

    m_pColorBuf[0] = m_c.GetR();
    m_pColorBuf[1] = m_c.GetG();
    m_pColorBuf[2] = m_c.GetB();
    m_pColorBuf[3] = m_c.GetA();
}

GisLines::~GisLines(void)
{
    /*TODO: 实现着色器程序释放 */
    //m_pProgram->Release();
    free(m_pPosBuf);
    free(m_pColorBuf);
    free(m_arMatrix);
}


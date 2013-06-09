#include "GisLines.h" 

GisLines::GisLines(void)
{
    GisColor c;
    m_c = c;

    CreatAndLinkProgram("./glsl/LinesVertex.glsl", "./glsl/LinesFragment.glsl");
}

GisLines::GisLines(const std::vector<GisPoint> &points, GisColor c)
{ 
    AddPoints(points);
    SetColor(c);
    CreatAndLinkProgram("./glsl/LinesVertex.glsl", "./glsl/LinesFragment.glsl");
} 

void GisLines::SetColor(GisColor c)
{
    m_c = c;
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

void GisLines::draw(GLenum drawType)
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
    pColorBuf = (float *)malloc(4 * sizeof(float));

    j = 0;

#ifdef __DEBUG_GIS_TRACE_DRAWED_POINTS__
    printf("GisLines:\n");
#endif
    for(i=0;i<iMax;i++)
    {
        pVertexBuf[j++] = m_points[i].GetX();
        pVertexBuf[j++] = m_points[i].GetY(); 
#ifdef __DEBUG_GIS_TRACE_DRAWED_POINTS__
        printf("point %d:");
        m_points[i].print(NULL);
        fflush(stdout);
#endif
    }

    pColorBuf[0] = m_c.GetR();
    pColorBuf[1] = m_c.GetG();
    pColorBuf[2] = m_c.GetB();
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


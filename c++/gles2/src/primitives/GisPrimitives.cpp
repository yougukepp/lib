#include "GisPrimitives.h" 

GisPrimitives::GisPrimitives(void)
{
    GisColor c;
    SetColor(c);

    std::vector<GisPoint> points;
    points.clear();
    AddPoints(points);

    InitMatrix();

    CreatAndLinkProgram("./glsl/LinesVertex.glsl", "./glsl/LinesFragment.glsl");
}

GisPrimitives::GisPrimitives(const std::vector<GisPoint> &points, GisColor c)
{ 
    AddPoints(points);

    SetColor(c);

    InitMatrix();

    CreatAndLinkProgram("./glsl/LinesVertex.glsl", "./glsl/LinesFragment.glsl");
} 

void GisPrimitives::SetColor(GisColor c)
{
    m_c = c;
    SetGLColorBuf();
}

void GisPrimitives::CreatAndLinkProgram(const char *vShaderFileName,  const char *fShaderFileName)
{
    m_pProgram = new GisProgram();
    m_pProgram->SetVertexShader(vShaderFileName);
    m_pProgram->SetFragmentShader(fShaderFileName);
    m_pProgram->Link();
}

void GisPrimitives::AddPoints(const std::vector<GisPoint> &points)
{
    int iMax = 0;
    iMax = points.size();
    for(int i=0; i<iMax; i++)
    {
        m_points.push_back(points[i]);
    } 
    
    SetGLPosBuf();
}

void GisPrimitives::InitMatrix(void)
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

void GisPrimitives::Translate(float x, float y, float z)
{
    m_arMatrix[12] = x;
    m_arMatrix[13] = y;
    m_arMatrix[14] = z;
}

void GisPrimitives::Scale(float x, float y, float z)
{
    m_arMatrix[0] = x;
    m_arMatrix[5] = y;
    m_arMatrix[10] = z;
}

void GisPrimitives::Rotate(float angle, char axis)
{
    double sina = 0;
    double cosa = 0;

    sina = sin(angle);
    cosa = cos(angle);

    if(0 == axis)                       // 围绕x轴旋转
    {
        m_arMatrix[5] = cosa;
        m_arMatrix[6] = sina;
        m_arMatrix[9] = -sina;
        m_arMatrix[10] = cosa;
    }
    else if(1 == axis)                  // 围绕y轴旋转
    {
        m_arMatrix[0] = cosa;
        m_arMatrix[2] = -sina;
        m_arMatrix[8] = sina;
        m_arMatrix[10] = cosa;
    }
    else if(2 == axis)                  // 围绕z轴旋转
    {
        m_arMatrix[0] = cosa;
        m_arMatrix[1] = sina;
        m_arMatrix[4] = -sina;
        m_arMatrix[5] = cosa;
    }
    else
    {
        assert(0);
    }

}

void GisPrimitives::DrawTriangles(GLenum drawType)
{
    assert((GL_TRIANGLES == drawType)
         ||(GL_TRIANGLE_STRIP == drawType)
         ||(GL_TRIANGLE_FAN == drawType));
    Draw(drawType);
}

void GisPrimitives::DrawLines(GLenum drawType)
{
    assert((GL_LINES == drawType)
         ||(GL_LINE_STRIP == drawType)
         ||(GL_LINE_LOOP == drawType));
    Draw(drawType);
}

void GisPrimitives::Draw(GLenum drawType)
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

void GisPrimitives::SetGLPosBuf(void)
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
        m_points[i].Print();
        fflush(stdout);
#endif
    }

}

void GisPrimitives::SetGLColorBuf(void)
{
    m_pColorBuf = (float *)malloc(m_cColorPerVertex * sizeof(float));
    assert(NULL != m_pColorBuf);

    m_pColorBuf[0] = m_c.GetR();
    m_pColorBuf[1] = m_c.GetG();
    m_pColorBuf[2] = m_c.GetB();
    m_pColorBuf[3] = m_c.GetA();
}

GisPrimitives::~GisPrimitives(void)
{
    /*TODO: 实现着色器程序释放 */
    //m_pProgram->Release();
    free(m_pPosBuf);
    free(m_pColorBuf);
    free(m_arMatrix);
}


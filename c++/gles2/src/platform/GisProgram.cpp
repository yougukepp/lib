#include "GisProgram.h"

GisProgram::GisProgram(void)
{
    m_pVertexShader = new GisShader();
    m_pFragmentShader = new GisShader();
} 

void GisProgram::setVertexShader(const char *pFileName)
{
    m_pVertexShader->ReadSrc(pFileName);
}

void GisProgram::setFragmentShader(const char *pFileName)
{
    m_pFragmentShader->ReadSrc(pFileName);
}

void GisProgram::Link(void)
{
    unsigned int vShaderId = 0;
    unsigned int fShaderId = 0;
    GLint linked = 0;

    vShaderId = m_pVertexShader->Compile(GL_VERTEX_SHADER);
    assert(0 != vShaderId);
    fShaderId = m_pFragmentShader->Compile(GL_FRAGMENT_SHADER);
    assert(0 != fShaderId);

    m_programId = glCreateProgram();
    assert(0 != m_programId);

    glAttachShader(m_programId, vShaderId);
    glAttachShader(m_programId, fShaderId);

    glLinkProgram(m_programId);

    glGetProgramiv(m_programId, GL_LINK_STATUS, &linked); 
    if(!linked) 
    {
        GLint infoLen = 0;

        glGetProgramiv(m_programId, GL_INFO_LOG_LENGTH, &infoLen);

        if(infoLen > 1)
        {
            GLchar* infoLog = (GLchar *)malloc(sizeof(GLchar) * infoLen);

            glGetProgramInfoLog(m_programId, infoLen, NULL, infoLog);
            fprintf(stderr, "着色器程序链接错误(Error linking program):%s\n", infoLog);
            fflush(stderr);

            free(infoLog);
        }

        glDeleteProgram(m_programId);
        exit(0);
    }

#if 0
    /* TODO:
     * 查看EsLoaderProgram, 需要找到合适的释放着色器的时机 */
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
#endif
}

void GisProgram::Use(void)
{ 
    glUseProgram(m_programId);
} 

void GisProgram::BindUniform4fv(const char *uniformName, float *pValue)
{
    GLint uniformHandle = 0;
    uniformHandle = glGetUniformLocation(m_programId, uniformName);
    assert(-1 != uniformHandle);
    glUniform4fv(uniformHandle, 1, pValue);
} 

void GisProgram::BindUniformMatrix4fv(const char *uniformName, float *pValue)
{
    GLint uniformHandle = 0;
    uniformHandle = glGetUniformLocation(m_programId, uniformName);
    assert(-1 != uniformHandle);

    glUniformMatrix4fv(uniformHandle, 1, 0, pValue);
}


int GisProgram::GetAttribLocation(const char *AttribName)
{
    int loc = 0;
    loc = glGetAttribLocation(m_programId, "vPosition");
    assert(-1 != loc);
    return loc;
}


#ifndef __GIS_PROGRAM_H__
#define __GIS_PROGRAM_H__

#include "GisShader.h"

class GisProgram
{
public:
    GisProgram(void);

    void setVertexShader(const char *pFileName);
    void setFragmentShader(const char *pFileName); 
    void Link(void); 
    
    void Use(void); 
    void BindUniform4fv(const char *uniformName, float *color);
    void BindUniformMatrix4fv(const char *uniformName, float *pValue);
    int GetAttribLocation(const char *AttribName);

protected:

private:
    GisShader *m_pVertexShader;
    GisShader *m_pFragmentShader;
    unsigned int m_programId;
};

#endif


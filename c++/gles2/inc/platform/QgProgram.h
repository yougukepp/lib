#ifndef __QG_PROGRAM_H__
#define __QG_PROGRAM_H__

#include "QgShader.h"

class QgProgram
{
public:
    QgProgram(void);

    void SetVertexShader(const char *pFileName);
    void SetFragmentShader(const char *pFileName); 
    void Link(void); 
    
    void Use(void); 
    void BindUniform4fv(const char *uniformName, float *color);
    void BindUniformMatrix4fv(const char *uniformName, float *pValue);
    int GetAttribLocation(const char *AttribName);

protected:

private:
    QgShader *m_pVertexShader;
    QgShader *m_pFragmentShader;
    unsigned int m_programId;
};

#endif


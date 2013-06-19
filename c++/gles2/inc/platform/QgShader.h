#ifndef __QG_SHADER_H__
#define __QG_SHADER_H__

#include "QgConfig.h"
#include "QgInnerInterface.h"

class QgShader
{
public:
    QgShader(void); 
    void ReadSrc(const char *pFileName);
    unsigned int Compile(GLenum type);

protected:

private:
    std::string m_src;
};

#endif


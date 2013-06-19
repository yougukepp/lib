#ifndef __GIS_SHADER_H__
#define __GIS_SHADER_H__

#include "GisConfig.h"
#include "GisInnerInterface.h"

class GisShader
{
public:
    GisShader(void); 
    void ReadSrc(const char *pFileName);
    unsigned int Compile(GLenum type);

protected:

private:
    std::string m_src;
};

#endif


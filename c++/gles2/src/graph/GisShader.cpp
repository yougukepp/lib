#include "GisShader.h"

void GisShader::ReadSrc(const char *pFileName)
{
    FILE *f = NULL;
    int readBytes = 0;
    char buf[GIS_SHADER_SRC_BUF];

    f = fopen(pFileName, "r"); 
    assert(NULL != f);

    while(!feof(f))
    {
        readBytes = fread(buf, 1, GIS_SHADER_SRC_BUF, f);
        assert(readBytes < GIS_SHADER_SRC_BUF);
        m_src.append(buf, readBytes);
    }
} 

GisShader::GisShader(void)
{
    ;
} 

unsigned int GisShader::Compile(GLenum type)
{
   GLuint shaderId = 0;
   GLint compiled = 0;
   const GLchar *pSrc = NULL;
   
   shaderId = glCreateShader(type);
   assert(0 != shaderId);

   pSrc = (const GLchar *)m_src.data();
   glShaderSource(shaderId, 1, &pSrc, NULL);
   glCompileShader(shaderId);

   /* 检查是否编译成功 */
   glGetShaderiv(shaderId, GL_COMPILE_STATUS, &compiled);
   if(!compiled)
   {
      GLint infoLen = 0;
      glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &infoLen);
      
      if(infoLen > 1)
      {
         GLchar* infoLog = (GLchar *)malloc(sizeof(GLchar) * infoLen);

         glGetShaderInfoLog (shaderId, infoLen, NULL, infoLog);
         fprintf(stderr, "Error compiling shaderId:%s\n", infoLog);            
         fprintf(stderr, "shaderId content:\n%s", m_src.data());
         fflush(stderr);
         
         free(infoLog);
      }

      glDeleteShader ( shaderId );
      exit(0);
   }

   return shaderId;
}


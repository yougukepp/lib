/*****************************************************************
 * Copyright(c) 2012, 武汉中原电子集团 应用电子研发中心
 * All rights reserved.
 * *
 * 文件名称:
 *
 * 摘要:
 *
 * 作者:
 *
 * 完成日期:
 *****************************************************************/
/*--------------------------- 预处理区 --------------------------*/
/***************************** 头文件 ****************************/
#include <stdlib.h>
#include "utils.h"
#include "shader.h"

/*-------------------------- 变量实现区 -------------------------*/
/**************************** 全局变量 ***************************/

/**************************** 文件变量 ***************************/

/*------------------------ 局部函数声明区 -----------------------*/

/*-------------------------- 函数实现区 --------------------------*/
static GLuint EsLoadShader(GLenum type, const GLchar* shaderSrc)
{
   GLuint shader;
   GLint compiled;
   
   shader = glCreateShader(type);

   if(0 == shader)
   {
       return 0;
   }

   glShaderSource(shader, 1, &shaderSrc, NULL);
   glCompileShader(shader);

   /* Check the compile status */
   glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);

   if(!compiled)
   {
      GLint infoLen = 0;
      glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);
      
      if(infoLen > 1)
      {
         GLchar* infoLog = (GLchar *)malloc(sizeof(GLchar) * infoLen);

         glGetShaderInfoLog (shader, infoLen, NULL, infoLog);
         printf("Error compiling shader:%s\n", infoLog);            
         printf("shader content:\n%s", shaderSrc);
         
         free(infoLog);
      }

      glDeleteShader ( shader );
      return 0;
   }

   return shader;
}

GLuint EsLoaderProgram(const GLchar* vertexShaderSrc, const GLchar* fragmentShaderSrc)
{
    GLuint vertexShader;
    GLuint fragmentShader;
    GLuint programObject;

    vertexShader = EsLoadShader(GL_VERTEX_SHADER, vertexShaderSrc);
    if (0 == vertexShader)
    {
        return 0;
    }

    fragmentShader = EsLoadShader(GL_FRAGMENT_SHADER, fragmentShaderSrc);
    if(0 == fragmentShader)
    {
        glDeleteShader(vertexShader);
        return 0;
    }

    programObject = glCreateProgram();

    if(0 == programObject)
    {
        return 0;
    }

    glAttachShader(programObject, vertexShader);
    glAttachShader(programObject, fragmentShader);

    return programObject;
}

GLvoid EsBindAttribLocation(GLint programId, GLchar *pAttr[], GLint size)
{
    GLint i = 0;
    for(i=0; i<size; i++)
    {
        /*printf("%d:%s\n", i, *pAttr);*/
        glBindAttribLocation(programId, i, *pAttr);
        pAttr++;
    }
}

GLvoid EsLinkProgram(GLint programId)
{
    GLint linked;

    glLinkProgram(programId);

    glGetProgramiv(programId, GL_LINK_STATUS, &linked);
    if(!linked) 
    {
        GLint infoLen = 0;

        glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &infoLen);

        if(infoLen > 1)
        {
            GLchar* infoLog = (GLchar *)malloc(sizeof(GLchar) * infoLen);

            glGetProgramInfoLog(programId, infoLen, NULL, infoLog);
            printf("Error linking program:%s\n", infoLog);

            free(infoLog);
        }

        glDeleteProgram(programId);
        return;
    }

#if 0
    /* TODO:
     * 查看EsLoaderProgram, 需要找到合适的释放着色器的时机 */
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
#endif
}

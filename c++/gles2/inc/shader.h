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
/* use __MX_SHADER__ not use __SHADER__ */
#ifndef         __SHADER_H__
#define         __SHADER_H__
/***************************** 头文件 ****************************/
#include        <GLES2/gl2.h>

/***************************** 宏定义 ****************************/

/*-------------------------- 接口声明区 -------------------------*/

/**************************** 全局变量 ***************************/

/*--------------------------- 接口函数 --------------------------*/
GLuint EsLoaderProgram(const GLchar* vertexShaderSrc, const GLchar* fragmentShaderSrc);

GLvoid ESUseProgram(GLint programObject);

GLint ESGetUniformLoacation(GLint programObject, const GLchar *varName);

GLvoid EsBindAttribLocation(GLint programId, GLchar **pAttr, GLint size);

GLvoid EsLinkProgram(GLint programId);

#endif

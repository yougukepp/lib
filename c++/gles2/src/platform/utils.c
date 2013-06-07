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
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

/*-------------------------- 变量实现区 -------------------------*/
/**************************** 全局变量 ***************************/

/**************************** 文件变量 ***************************/

/*------------------------ 局部函数声明区 -----------------------*/

/*-------------------------- 函数实现区 --------------------------*/
void ReadShaderSrc(const char *fileName, char *buf, int bufLength)
{
    FILE *f = NULL;
    int readBytes = 0;

    f = fopen(fileName, "r"); 
    if(NULL == f)
    {
        printf("%s,%d:ERROR: Can't Open file:%s\n", __FILE__, __LINE__, fileName);
        exit(0);
    }
    
    readBytes = fread(buf, 1, bufLength, f);

    /* over flow */
    if(readBytes >= bufLength)
    {
        printf("%s,%d:ERROR: buf is not enough!\n", __FILE__, __LINE__);
        buf[bufLength - 1] = '\0';
    }

    fclose(f);
    return;
}


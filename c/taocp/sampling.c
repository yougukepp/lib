/*****************************************************************
 * Copyright(c) 2012, 武汉中原电子集团 应用电子研发中心
 * All rights reserved.
 * *
 * 文件名称:
 *
 * 摘要:
 *
 * 作者:PengPeng <yougukepp@gmail.com>
 *
 * 完成日期:
 *****************************************************************/
/*--------------------------- 预处理区 --------------------------*/

/***************************** 头文件 ****************************/
#include <assert.h>
#include <stdio.h>
#include "myself.h"
#include "taocp.h"

/*----------------------------- 声明区 --------------------------*/

/**************************** 变量声明区 *************************/

/**************************** 函数声明区 *************************/

/*************************** 变量实现区 **************************/

/*************************** 函数实现区 **************************/
void sampling(int needNums, int sampleNums, int *pBuf)
{
    assert(0 <= needNums);
    assert(needNums <= sampleNums);

    int i = 0;
    int dealedNums = 0;
    int readySampleNums = 0;

    if(needNums <= 0)
    {
        return;
    }

    while(true)
    {
        double aUniform = getRangeRand(0, 1);

        if(((sampleNums - dealedNums) * aUniform) < (needNums - readySampleNums))
        {
            
#ifdef TAOCP_DEBUG
            printf("%d, %d\n", i, needNums);
            fflush(stdout);
            assert(i < needNums);
#endif

            pBuf[i] = dealedNums;
            i++;
            readySampleNums++;
            if(readySampleNums == needNums)
            {
                break;
            }
        }
        dealedNums += 1;
    }
}


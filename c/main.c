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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myself.h"
#include "taocp.h"
#include "sicp.h"


/*----------------------------- 声明区 --------------------------*/

/**************************** 变量声明区 *************************/


/**************************** 函数声明区 *************************/
static void gcdTest(void);
static void samplingTest(void);
static void factorialTest(void);
static void fibonacciTest(void);


/*************************** 变量实现区 **************************/


/*************************** 函数实现区 **************************/
int main(int argc, char *argv[])
{
    gcdTest();
    samplingTest();
    factorialTest();
    fibonacciTest();

    return 0;
}

static void gcdTest(void)
{
    printf("gcd test begin:\n");
    printf("gcd(17, 68) = %d\n", gcd(17,68));
    printf("gcd test end.\n\n");
}

static void samplingTest(void)
{
    int i = 0;
    int pBuf[5];

    printf("sampling test begin: form [0,10) sampling 3 samples\n");
    for(i=0;i<3;i++)
    {
        printf("%dtimes result:", i);
        memset(pBuf, 0, 5);
        sampling(5, 10, pBuf);
        print(pBuf, 5);
    }
    printf("sampling test end.\n\n");

    return;
}

static void factorialTest(void)
{
    int n = 0;
    for(n=50;n<100;n++)
    {
        printf("%llu,", factorial(n));
    }

    printf("\n\n");
}

static void fibonacciTest(void)
{
    int n = 0;
    for(n=50;n<100;n++)
    {
        printf("%llu,", fibonacci(n));
    }
    printf("\n\n");
}


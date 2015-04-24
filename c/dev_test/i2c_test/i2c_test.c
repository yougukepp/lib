/******************************************************************************
 *
 * 文件名  ： i2c_tect.c
 * 负责人  ： 彭鹏(pengpeng@fiberhome.com)
 * 创建日期： 20150408 
 * 版本号  ： v1.0
 * 文件描述： i2c驱动测试代码
 * 版权说明： Copyright (c) 2000-2020   烽火通信科技股份有限公司
 * 其    他： 无
 * 修改日志： 无
 *
 *******************************************************************************/


/*---------------------------------- 预处理区 ---------------------------------*/

/************************************ 头文件 ***********************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "fhdrv_i2c.h"

#define BUF_SIZE    (1024)

/*----------------------------------- 声明区 ----------------------------------*/

/********************************** 变量声明区 *********************************/


/********************************** 函数声明区 *********************************/


/********************************** 变量实现区 *********************************/


/********************************** 函数实现区 *********************************/
/*******************************************************************************
 *
 * 函数名  : main
 * 负责人  : 彭鹏
 * 创建日期: 无
 * 函数功能: 主函数
 *
 * 输入参数: argc - 参数个数
 *           argv - 命令行参数数组
 *
 * 输出参数: 无
 *
 * 返回值:   0   : 正常退出
 *           其它: 异常退出
 * 调用关系: 无
 * 其 它:    无
 *
 ******************************************************************************/
int main(int argc, char *argv[])
{
    int rst = 0;
    int channel = 0;
    int addr = 0;
    int offset = 0;
    int size = 0;
    char buf[BUF_SIZE];
    bzero(buf, BUF_SIZE);

    if(5 != argc)
    {
        fprintf(stderr, "Usage:%s channel addr(dec) offset(dec) size(byte)\n", argv[0]);
        return 0;
    }

    channel = atoi(argv[1]);
    addr = atoi(argv[2]);
    offset = atoi(argv[3]);
    size = atoi(argv[4]);

    printf("read from addr:0x%x offset:%d %d bytes:\n", addr, offset, size); 
    
    rst = fhdrv_i2c_read(channel, addr, offset, buf, size);
    if(0 != rst)
    {
        fprintf(stderr, "fh_i2c_read failed:%d\n", rst);
        return 0;
    }

    printf("string:");
    for(int i=0; i<size; i++)
    {
        printf("%c", buf[i]);
    } 
    
    printf("\nchar:  ");
    for(int i=0; i<size; i++)
    {
        printf("0x%x,", buf[i]);
    }
    printf("\n");

    return 0;
}



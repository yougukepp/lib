/******************************************************************************
 *
 * 文件名  ： 
 * 负责人  ： 彭鹏(pengpeng@fiberhome.com)
 * 创建日期： 20150116 
 * 版本号  ： 
 * 文件描述： 
 * 版权说明： Copyright (c) 2000-2020   烽火通信科技股份有限公司
 * 其    他： 无
 * 修改日志： 无
 *
 *******************************************************************************/


/*---------------------------------- 预处理区 ---------------------------------*/

/************************************ 头文件 ***********************************/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <error.h>
#include <errno.h>
#include <stdlib.h>

#include "header.h"


/*----------------------------------- 声明区 ----------------------------------*/

/********************************** 变量声明区 *********************************/


/********************************** 函数声明区 *********************************/
static int get_range_rand(int min, int max);


/********************************** 变量实现区 *********************************/


/********************************** 函数实现区 *********************************/
int main(int argc, char *argv[])
{
    int write_fifo_fd = 0;
    char buf[PM_BUF_SIZE] = {0}; 
    int nwrite = 0;

    for(int i = 0; i < PM_BUF_SIZE; i++)
    {
        buf[i] = get_range_rand(0,10);
    }
    
    fprintf(stdout, "%s:begin open for write.\n", __FILE__);
    write_fifo_fd = open(PM_FIFO_PATH, O_WRONLY, 0);

    fprintf(stdout, "%s:begin write.\n", __FILE__);
    nwrite = write(write_fifo_fd, buf, PM_BUF_SIZE);
    fprintf(stdout, "%s:data(%d):", __FILE__, nwrite);
    for(int i = 0; i < PM_BUF_SIZE; i++)
    {
        fprintf(stdout, "0x%02x,", buf[i]);
    }
    fprintf(stdout, "\b.\n");

    close(write_fifo_fd);

    printf("%s:over!\n", __FILE__);
    return 0;

}

static int get_range_rand(int min, int max)
{
    double rst = 0;

    /* 获取在[0,1)区间的均匀分布 */
    rst = 1.0 * rand() / RAND_MAX;

    /* 将[0,1)区间的均匀分布扩展到[min, max) */
    rst *= max - min;
    rst += min;

    return (int)rst;
} 


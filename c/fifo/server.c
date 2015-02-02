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
#include <string.h>

#include "header.h"



/*----------------------------------- 声明区 ----------------------------------*/

/********************************** 变量声明区 *********************************/


/********************************** 函数声明区 *********************************/


/********************************** 变量实现区 *********************************/


/********************************** 函数实现区 *********************************/
int main(int argc, char *argv[])
{
    int read_fifo_fd = 0;
    int dummy_fd = 0;
    int nread = 0;
    //char buf[PM_BUF_SIZE] = {0}; 
    char buf[100] = {0}; 

    if((mkfifo(PM_FIFO_PATH, PM_FIFO_MODE) < 0) && (errno != EEXIST))
    {
        fprintf(stderr, "file %s exists!\n", PM_FIFO_PATH);
        return 0;
    }

    fprintf(stdout, "%s:wait client open for write.\n", __FILE__);
    read_fifo_fd = open(PM_FIFO_PATH, O_RDONLY, 0);
    fprintf(stdout, "%s:client open for write.\n", __FILE__);
    do
    {
        fprintf(stdout, "%s:wait client write.\n", __FILE__);
        nread = read(read_fifo_fd, buf, 100); 
        fprintf(stdout, "%s:data(%d):", __FILE__, nread);
        int i = 0;
        for(i = 0; i < nread; i++)
        {
            fprintf(stdout, "0x%02x,", buf[i]);
        }
        fprintf(stdout, "\b.\n");

    }while(nread > 0);

    close(dummy_fd);
    close(read_fifo_fd);

    printf("%s:over!\n", __FILE__);
    return 0;

}



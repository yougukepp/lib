/******************************************************************************
 *
 * 文件名  ： usb_test.c
 * 负责人  ： 彭鹏(pengpeng@fiberhome.com)
 * 创建日期： 20150313 
 * 版本号  ： v1.0
 * 文件描述： 测试U盘速度
 * 版权说明： Copyright (c) 2000-2020   烽火通信科技股份有限公司
 * 其    他： 无
 * 修改日志： 无
 *
 *******************************************************************************/


/*---------------------------------- 预处理区 ---------------------------------*/

/************************************ 头文件 ***********************************/
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>

void sync(void);


//#define USB_FILE ("/dev/shm/usb/media/sda1/pp.r")
#define USB_FILE ("./pp.r")

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
    char *mem_buf = NULL;
    int mem_size = 0;
    int usb_file_fd_w = 0;
    int usb_file_fd_r = 0;
    ssize_t nwrite = 0;
    ssize_t nread = 0; 
    struct timeval start_time;
    struct timeval end_time;
    double time_use = 0;

    /* TODO: 参数检查 */
    if(2 != argc)
    {
        printf("./usb_test bytes.\n");
        return 0;
    }
    mem_size = atoi(argv[1]);

    mem_buf = (char *)malloc(mem_size);
    if(NULL == mem_buf)
    {
        fprintf(stderr, "%d\n", mem_size);
        perror("malloc(w)");
        return 0;
    }

    /* 生成随机内容 */
    for(int i=0;i<mem_size;i++)
    {
        mem_buf[i] = (char)(rand() % 0xff);
    }

    /* 写测试 */
    usb_file_fd_w = open(USB_FILE, O_WRONLY | O_CREAT);
    if(-1 == usb_file_fd_w)
    {
        fprintf(stderr, "%s\n", USB_FILE);
        perror("fopen(w)");
        return 0;
    } 
    
    printf("begin write.\n");

    sync();
    gettimeofday(&start_time, 0); 
    nwrite = write(usb_file_fd_w, mem_buf, mem_size);
    sync();
    gettimeofday(&end_time,0); 
    time_use = 1000000 * (end_time.tv_sec - start_time.tv_sec) + end_time.tv_usec - start_time.tv_usec; 
    printf("write %dBytes used %fms \n", mem_size, time_use/1000.0);
    if(mem_size != nwrite)
    {
        fprintf(stderr, "should write %d, but write %d.\n", mem_size, (int)nwrite);
        close(usb_file_fd_w);
        return 0;
    }

    printf("end write.\n");

    close(usb_file_fd_w);


    /* 读测试 */
    usb_file_fd_r = open(USB_FILE, O_RDONLY);
    if(-1 == usb_file_fd_r)
    {
        fprintf(stderr, "%s\n", USB_FILE);
        perror("fopen(r)");
        return 0;
    } 

    printf("begin read.\n");

    sync();
    gettimeofday(&start_time, 0); 
    nread = read(usb_file_fd_r, mem_buf, mem_size);
    sync();
    gettimeofday(&end_time,0); 
    time_use = 1000000 * (end_time.tv_sec - start_time.tv_sec) + end_time.tv_usec - start_time.tv_usec; 
    printf("read %dBytes used %fms\n", mem_size, time_use/1000.0);
    if(mem_size != nread)
    {
        fprintf(stderr, "should read %d, but read %d.\n", mem_size, (int)nread);
        close(usb_file_fd_r);
        return 0;
    }

    printf("end read.\n");

    close(usb_file_fd_r);

    free(mem_buf);
    
    return 0;
}



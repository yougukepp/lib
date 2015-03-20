/******************************************************************************
 *
 * 文件名  ： nand_test.c
 * 负责人  ： 彭鹏(pengpeng@fiberhome.com)
 * 创建日期： 20150320 
 * 版本号  ： v1.0
 * 文件描述： 测试Nand Flash
 * 版权说明： Copyright (c) 2000-2020   烽火通信科技股份有限公司
 * 其    他： 无
 * 修改日志： 无
 *
 *******************************************************************************/


/*---------------------------------- 预处理区 ---------------------------------*/

/************************************ 头文件 ***********************************/
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>

/* Kbytes */
#define NAND_K (1024)

/* Mbytes */
#define NAND_M ((NAND_K) * (NAND_K))

/*----------------------------------- 声明区 ----------------------------------*/

/********************************** 变量声明区 *********************************/


/********************************** 函数声明区 *********************************/
static int nand_test_write(int fd, const char *buf, int buf_size, int file_size);
static int nand_read_and_compare(int fd, const char *buf, int buf_size, int file_size);
static int test_main(const char *mem_buf, int mem_size, const char *file_name, int file_size);


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
 * 其 它:    由于内存没有文件大，所以文件中的内容是mem_buf内容的循环
 *
 ******************************************************************************/
int main(int argc, char *argv[])
{
    int rst = 0;
    char *mem_buf = NULL;
    int mem_size = 0;
    int times = 0;
    int file_size = 0;
    int show_interval = 0;
    char *file_name = NULL;

    struct timeval last_time;
    struct timeval now_time;
    time_t seconds_use = 0;

    if(6 != argc)
    {
        fprintf(stderr, "Usage:%s mem_size(kB) file_size(MB) times show_interval file_name\n", argv[0]);
        return 0;
    }

    mem_size = atoi(argv[1]) * NAND_K; /* mem以kBytes 为单位 */
    file_size = atoi(argv[2]);
    times = atoi(argv[3]); 
    show_interval = atoi(argv[4]); /* 以秒为单位 */ 
    file_name = argv[5];
    
    /* 1 => 100M*/
    if((mem_size <= 0) || (mem_size > 100 * NAND_M))
    {
        fprintf(stderr, "mem_size(%dkB) is unvalid.\n", mem_size);
        return 0;
    }

    /* 1 => 10G */
    if((file_size <= 0) || (file_size > 10 * NAND_K))
    {
        fprintf(stderr, "file_size(%dkB) is unvalid.\n", file_size);
        return 0;
    }

    /* 1 => 2^30(1G) */
    if((times <= 0) || (times > NAND_K * NAND_M))
    {
        fprintf(stderr, "times(%d) is unvalid.\n", times);
        return 0;
    }

    /* 1 => 1天(24 * 60 * 60) */
    if((show_interval <= 0) || (show_interval > (24*60*60)))
    {
        fprintf(stderr, "show_interval(%d) is unvalid.\n", show_interval);
        return 0;
    }
    
    /* 比较时需要使用同样大小的内存 故这里测试内存是否够用 */
    mem_buf = (char *)malloc(mem_size * 2);
    if(NULL == mem_buf)
    {
        fprintf(stderr, "%d\n", mem_size);
        perror("malloc");
        return 0;
    }
    free(mem_buf);
    mem_buf = NULL; /* 避免野指针 */

    /* 构造随机值 */
    mem_buf = (char *)malloc(mem_size);
    if(NULL == mem_buf)
    {
        fprintf(stderr, "%d\n", mem_size);
        perror("malloc");
        return 0;
    }

    srand(time(NULL));
    for(int i=0;i<mem_size;i++)
    {
        mem_buf[i] = (char)(rand() % 0xff);
    }

    /* TODO； 由于test_main会阻塞 故时间精度不准 */
    gettimeofday(&last_time, 0); 
    for(int i = 0; i < times; i++)
    {
        rst = test_main(mem_buf, mem_size, file_name, file_size);
        if(0 != rst)
        {
            return 0;
        } 
        
        
        gettimeofday(&now_time, 0); 
        seconds_use = now_time.tv_sec - last_time.tv_sec;
        if(seconds_use >= show_interval)
        { 
            /* 打印时间戳和正确信息 */
            time_t now;
            struct tm *time_now;
            time(&now);
            time_now = localtime(&now);

            fprintf(stderr, "PASS:%s", asctime(time_now)); /* asctime自带回车 */
            gettimeofday(&last_time, 0); 
        }
    } 

    
    printf("all test passed!\n");

    free(mem_buf);
    mem_buf = NULL; /* 避免野指针 */

    return 0;
}

static int test_main(const char *mem_buf, int mem_size, const char *file_name, int file_size)
{
    int nand_file_fd_w = 0;
    int nand_file_fd_r = 0;
    ssize_t nwrite = 0;
    ssize_t nread = 0; 
    
    /************************ 写入 *************************/
    /* 打开文件 */
    nand_file_fd_w = open(file_name, O_WRONLY | O_CREAT);
    if(-1 == nand_file_fd_w)
    {
        fprintf(stderr, "%s\n", file_name);
        perror("fopen(w)");
        return -1;
    } 

    /* 写入 */
    nwrite = nand_test_write(nand_file_fd_w, mem_buf, mem_size, file_size);
    if(file_size != nwrite)
    { 
        fprintf(stderr, "should write %dMBytes, but write %dMBytes.\n", file_size, (int)nwrite);
        close(nand_file_fd_w);
        return -1;
    }

    /* 关闭文件 */
    close(nand_file_fd_w);
    /********************** 写入完成 ***********************/

    /************************ 读取测试 *************************/
    nand_file_fd_r = open(file_name, O_RDONLY);
    if(-1 == nand_file_fd_r)
    {
        fprintf(stderr, "%s\n", file_name);
        perror("fopen(r)");
        return -1;
    } 

    nread = nand_read_and_compare(nand_file_fd_r, mem_buf, mem_size, file_size);
    if(file_size != nread) /* 比对未通过 */
    {
        fprintf(stderr, "should read %dMBytes, but read %dMBytes.\n", file_size, (int)nread);
        close(nand_file_fd_r);
        return -1;
    }

    close(nand_file_fd_r);
    /********************** 读取测试完成 ***********************/

    return 0;
}

static int nand_test_write(int fd, const char *buf, int buf_size, int file_size)
{
    int left = 0;
    int div = 0;
    long long file_size_byte = 0;

    ssize_t nwrite = 0;
    long long all_write = 0;

    file_size_byte = file_size * NAND_M; /* file_size以MB为单位, buf_size以kByte为单位 */

    div = file_size_byte / buf_size;
    left = file_size_byte % buf_size;
    
    for(int i = 0; i < div; i++)
    { 
        nwrite = write(fd, buf, buf_size);
        if(buf_size != nwrite)
        {
            fprintf(stderr, "should write %d, but write %d.\n", buf_size, (int)nwrite);
            goto RETURN;
        }
        all_write += nwrite;
    } 
    
    nwrite = write(fd, buf, left);
    if(left != nwrite)
    {
        fprintf(stderr, "should write %d, but write %d.\n", buf_size, (int)nwrite);
        goto RETURN;
    } 
    all_write += nwrite;

    all_write /= NAND_M;

RETURN:

    sync();
    sync();
    sync();

    return all_write;
} 

static int nand_read_and_compare(int fd, const char *buf, int buf_size, int file_size)
{
    int times = 0;
    ssize_t nread = 0;
    char *read_buf = NULL;
    long long all_read = 0;

    read_buf = (char *)malloc(buf_size);
    if(NULL == read_buf)
    {
        fprintf(stderr, "%d\n", buf_size);
        perror("malloc");
        return 0;
    }

    do{ 
        bzero(read_buf, buf_size);
        nread = read(fd, read_buf, buf_size);
        if(-1 == nread)
        { 
            perror("read:");
            return all_read;
        } 

        /* 比对 */
        for(int i = 0; i < nread; i++)
        {
            if(read_buf[i] != buf[i])
            {
                printf("file error in offset:%llu, 0x%02x => 0x%02x\n",
                        all_read + i, (char)buf[i], read_buf[i]);
                goto ERR;
            }
        }
        
        /* nread <= buf_size 计入读取总数字 */
        all_read +=  nread;
        times++;

        if(nread < buf_size)
        {
            break;
        }
    }while(1);

ERR:

    free(read_buf);
    read_buf = NULL; /* 避免野指针 */

    all_read /= NAND_M;
    if(all_read != file_size)
    {
        fprintf(stderr, "file size change from:%dMBytes to:%lluMBytes\n", file_size, all_read);
    } 

    sync();
    sync();
    sync();
    
    return all_read;
}


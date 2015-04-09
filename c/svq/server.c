/******************************************************************************
 *
 * 文件名  ： sever.c
 * 负责人  ： 彭鹏(pengpeng@fiberhome.com)
 * 创建日期： 20150116 
 * 版本号  ： v1.0
 * 文件描述： 消息队列服务器端
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
#include <sys/ipc.h>
#include <sys/msg.h>

#include "svq.h"


/*----------------------------------- 声明区 ----------------------------------*/

/********************************** 变量声明区 *********************************/


/********************************** 函数声明区 *********************************/


/********************************** 变量实现区 *********************************/


/********************************** 函数实现区 *********************************/
int main(int argc, char *argv[])
{
    int rst = 0;
    int svq_id = 0;
    size_t nrecv = 0; 
    
    SVQ_MSG msg;

    /* 消息初始化 */
    msg.type = 0;
    for(int i = 0; i < SVQ_MSG_LEN; i++)
    {
        msg.data[i] = NUL;
    }


    /* 读写权限创建 */
    svq_id = msgget((key_t)SVQ_KEY, 0666 | IPC_CREAT);
    if( -1 == svq_id)
    {
        perror("msgget");
        exit(1);
    }
#ifdef SVQ_DEBUG
    printf("system v queue created.\n");
#endif


    /* 接受client消息 */
    /* 先到先收 & 阻塞接收 */
#ifdef SVQ_DEBUG
    printf("prepare recv.\n");
#endif
    nrecv = msgrcv(svq_id, &msg, SVQ_MSG_LEN, 0, 0);
    if( -1 == nrecv)
    {
        perror("msgrcv");
        exit(1);
    }
#ifdef SVQ_DEBUG
    printf("recv:");
    printf("type:%ld,data:", msg.type);
    for(int i = 0; i < 10; i++)
    {
        printf("%c,", msg.data[i]);
    }
    printf("\b.\n");
#endif


    /* 将消息中小写字母替换为数字 */
    msg.type = 1;
    for(int i = 0; i < SVQ_MSG_LEN; i++)
    {
        if(i < 10)
        {
            msg.data[i] = '0' + i;
        }
        else
        {
            msg.data[i] = NUL;
        }
    }


    /* 阻塞发送 */
#ifdef SVQ_DEBUG
    printf("prepare send.\n");
#endif
    rst = msgsnd(svq_id, &msg, SVQ_MSG_LEN, 0);
    if( -1 == rst )
    {
        perror("msgsnd");
        exit(1);
    }
#ifdef SVQ_DEBUG
    printf("send:");
    printf("type:%ld,data:", msg.type);
    for(int i = 0; i < 10; i++)
    {
        printf("%c,", msg.data[i]);
    }
    printf("\b.\n");
#endif


    /* 删除消息队列 */
    rst = msgctl(svq_id, IPC_RMID, NULL);
    if( -1 == rst)
    {
        perror("msgctl");
        exit(1);
    }
#ifdef SVQ_DEBUG
    printf("system v queue delete.\n");
#endif
}



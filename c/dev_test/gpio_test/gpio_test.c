/******************************************************************************
 *
 * 文件名  ： gpio_tect.c
 * 负责人  ： 彭鹏(pengpeng@fiberhome.com)
 * 创建日期： 20150429 
 * 版本号  ： v1.0
 * 文件描述： gpio驱动测试代码
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

#include "fhdrv_gpio.h"

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
    int gpio = 0;
    char r_or_w = 0;
    unsigned char val = 0;

    if(!((4 == argc)
      || (3 == argc)))
    {
        fprintf(stderr, "Usage:%s gpio r(or w) val.\n", argv[0]);
        return 0;
    }

    gpio = atoi(argv[1]);
    r_or_w = *argv[2];

    /* printf("%d,%c,%d,%d\n", r_or_w, r_or_w, 'r', 'w'); */
    if('r' == r_or_w) /* read */
    {
        printf("read from:");
    }
    else if('w' == r_or_w) /* write */
    {
        val = (unsigned char)atoi(argv[3]);
        printf("write to:");
    }
    else /* error */
    {
        fprintf(stderr, "Usage:%s gpio r(0)w(1) val.\n", argv[0]);
        return 0;
    }

    rst = fhdrv_gpio_set_pinmux(gpio, 5); /* set pin to gpio mode */
    if(0 != rst)
    {
        fprintf(stderr, "fhdrv_gpio_set_pinmux error.\n");
        return 0;
    }

    if('r' == r_or_w) /* read */
    {
        rst = fhdrv_gpio_set_mode(gpio, 0); /* 0 in, 1 out */
        if(0 != rst)
        {
            fprintf(stderr, "fhdrv_gpio_set_mode error.\n");
            return 0;
        }

        rst = fhdrv_gpio_read(gpio, &val);
        if(0 != rst)
        {
            fprintf(stderr, "fhdrv_gpio_read error.\n");
            return 0;
        }

    }
    else /* write */
    {
        rst = fhdrv_gpio_set_mode(gpio, 1); /* 0 in, 1 out */
        if(0 != rst)
        {
            fprintf(stderr, "fhdrv_gpio_set_mode error.\n");
            return 0;
        }

        rst = fhdrv_gpio_write(gpio, val);
        if(0 != rst)
        {
            fprintf(stderr, "fhdrv_gpio_write error.\n");
            return 0;
        }
    }

    printf("gpio%d %s\n", gpio, (1 == val)?("High"):("Low")); 

    return 0;
}



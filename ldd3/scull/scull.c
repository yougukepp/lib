/******************************************************************************
 *
 * 文件名  ： scull.c
 * 负责人  ： 彭鹏(pengpeng@fiberhome.com)
 * 创建日期： 20150413 
 * 版本号  ： v1.0
 * 文件描述： LDD3中第三章scull驱动实现
 * 版权说明： Copyright (c) 2000-2020 Dual BSD/GPL
 * 其    他： pp 用于练习写驱动
 * 修改日志： 无
 *
 *******************************************************************************/
/*---------------------------------- 预处理区 ---------------------------------*/

/************************************ 头文件 ***********************************/
#include <linux/init.h>
#include <linux/module.h>

#include "scull.h"


/*----------------------------------- 声明区 ----------------------------------*/

/********************************** 变量声明区 *********************************/
/* 主设备号使用模块参数 */
static unsigned int s_scull_major = SCULL_MAJOR;
module_param(s_scull_major, uint, S_IRUGO);

/* 版本号 */
static dev_t s_dev_num;

/* 设备结构体 */
static struct scull_dev dev;

/********************************** 函数声明区 *********************************/ 
static void scull_setup_cdev(struct scull_dev *dev);


/********************************** 变量实现区 *********************************/


/********************************** 函数实现区 *********************************/
int scull_open(struct inode *inode, struct file *filp)
{
    /* 无需操作 */

    printk(KERN_ALERT "scull open ok.\n");
    return 0;
}

int scull_release(struct inode *inode, struct file *filp)
{
    /* 无需操作 */

    printk(KERN_ALERT "scull release ok.\n");
    return 0;
}

ssize_t scull_read(struct file *filp, char __user *buff,
        size_t count, loff_t *offp)
{
    printk(KERN_ALERT "scull read ok.\n");
    return 0;
}

ssize_t scull_write(struct file *filp, const char __user *buff,
        size_t count, loff_t *offp)
{
    printk(KERN_ALERT "scull write ok.\n");
    return 0;
}


/*******************************************************************************
 *
 * 函数名  : scull_init
 * 负责人  : 彭鹏
 * 创建日期: 无
 * 函数功能: 模块初始化
 *
 * 输入参数: 无
 * 输出参数: 无
 *
 * 返回值:   模块初始化是否正常 通常为0
 * 调用关系: 无
 * 其 它:    无
 *
 ******************************************************************************/
static int scull_init(void)
{
    int result = 0;

    /* 分配 设备号 */
    if(s_scull_major)
    { 
        printk(KERN_ALERT "static malloc dev_t no support.\n");
        return 0;
    }
    else /* 动态分配 */
    {
        result = alloc_chrdev_region(&s_dev_num, 0, 1, SCULL_NAME);
        s_scull_major = MAJOR(s_dev_num);
    }

    /* 注册字符设备 */
    scull_setup_cdev(&dev);

    printk(KERN_ALERT "scull init ok.\n");
    return 0;
}

/*******************************************************************************
 *
 * 函数名  : scull_exit
 * 负责人  : 彭鹏
 * 创建日期: 无
 * 函数功能: 主函数
 *
 * 输入参数: 无 
 * 输出参数: 无
 *
 * 返回值:   无
 * 调用关系: 无
 * 其 它:    无
 *
 ******************************************************************************/
static void scull_exit(void)
{ 
    cdev_del(&dev.cdev);
    unregister_chrdev_region(s_dev_num, 1);

    printk(KERN_ALERT "scull exit ok.\n");
}

static void scull_setup_cdev(struct scull_dev *dev)
{
    int err = 0;
    dev_t devno = MKDEV(s_scull_major, 0);

    cdev_init(&dev->cdev, &scull_fops);
    dev->cdev.owner = THIS_MODULE;
    dev->cdev.ops = &scull_fops;

    err = cdev_add(&dev->cdev, devno, 1);
    if(err)
    {
        printk(KERN_ALERT "cdev_add err:%d\n", err);
    }
}

module_init(scull_init);
module_exit(scull_exit);

MODULE_LICENSE("Dual BSD/GPL");


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
#include <linux/slab.h>
#include <asm/uaccess.h>

#include "scull.h"


/*----------------------------------- 声明区 ----------------------------------*/

/********************************** 变量声明区 *********************************/
/* 设备结构体 */
static struct scull_dev s_dev;

/********************************** 函数声明区 *********************************/ 
static void scull_setup_cdev(struct scull_dev *dev, unsigned int scull_major);


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
    unsigned int read_count = 0;
    unsigned long copy_count = 0;

    if(count > SCULL_MEM_SIZE)
    {
        printk(KERN_ALERT "scull read should small than 0x%x, but give me 0x%x.\n", 
                SCULL_MEM_SIZE, (unsigned int)count);
        return -EFAULT;
    }

     /* TODO: 锁 */
    if(s_dev.size < count)
    {
        read_count = s_dev.size;
    }
    else
    {
        read_count = count;
    }

    copy_count = copy_to_user(buff, s_dev.data, read_count);
    if(0 != copy_count)
    {
        return -EFAULT;
    }

    printk(KERN_ALERT "scull read ok.\n");
    return read_count;
}

ssize_t scull_write(struct file *filp, const char __user *buff,
        size_t count, loff_t *offp)
{
    char *k_buf = NULL;
    unsigned long copy_count = 0;

    if(count > SCULL_MEM_SIZE)
    {
        printk(KERN_ALERT "scull read should small than 0x%x, but give me 0x%x.\n", 
                SCULL_MEM_SIZE, (unsigned int)count);
        return -EFAULT;
    }

    /* 申请内存 */
    k_buf = kmalloc(count, GFP_KERNEL);
    if(NULL == k_buf)
    { 
        printk(KERN_ALERT "%s,%d:kmalloc failed.\n", __FILE__, __LINE__);
        return -ENOMEM;
    }

    /* 拷贝用户数据 */
    copy_count = copy_from_user(k_buf, buff, count);
    if(0 != copy_count)
    {
        return -EFAULT;
    }

    /* 存入scull_dev
     * TODO: 锁
     * */
    memcpy(s_dev.data, k_buf, count);
    s_dev.size += count;

    kfree(k_buf);

    printk(KERN_ALERT "scull write ok.\n");
    return count;
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
    int i = 0;
    int result = 0; 
    unsigned int scull_major = 0;
    unsigned char *go = NULL;

    /* 分配内存 */
    s_dev.size = 0;
    s_dev.data = (unsigned char *)kmalloc(SCULL_MEM_SIZE, GFP_KERNEL);

    go = s_dev.data;
    for(i = 0; i < SCULL_MEM_SIZE; i++)
    {
        go[i] = '\0';
    }

    /* 动态分配 */
    result = alloc_chrdev_region(&s_dev.dev_num, 0, 1, SCULL_NAME);
    scull_major = MAJOR(s_dev.dev_num);

    /* 注册字符设备 */
    scull_setup_cdev(&s_dev, scull_major);

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
    cdev_del(&s_dev.cdev);
    unregister_chrdev_region(s_dev.dev_num, 1);

    /* 释放内存 */
    kfree(s_dev.data);
    s_dev.size = 0;

    printk(KERN_ALERT "scull exit ok.\n");
}

static void scull_setup_cdev(struct scull_dev *dev, unsigned int scull_major)
{
    int err = 0;
    dev_t devno = MKDEV(scull_major, 0);

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


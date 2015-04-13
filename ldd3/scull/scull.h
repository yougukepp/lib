/******************************************************************************
 *
 * 文件名  ： scull.h
 * 负责人  ： 彭鹏(pengpeng@fiberhome.com)
 * 创建日期： 20150413 
 * 版本号  ： v1.0
 * 文件描述： LDD3中第三章scull驱动头文件
 * 版权说明： Copyright (c) 2000-2020 Dual BSD/GPL
 * 其    他： 无
 * 修改日志： 无
 *
 *******************************************************************************/
/*---------------------------------- 预处理区 ---------------------------------*/
#ifndef _SCULL_H_
#define _SCULL_H_

/************************************ 头文件 ***********************************/
#include <linux/fs.h>
#include <linux/cdev.h>

/************************************ 宏定义 ***********************************/
/* 默认0 表示动态分配住设备号 */
#define SCULL_MAJOR                     (0)

/* 设备名 */
#define SCULL_NAME                      ("scull")

/*********************************** 类型定义 **********************************/
struct scull_dev {
    int data;
    struct cdev cdev; /* 字符设备 */
};

/*--------------------------------- 接口声明区 --------------------------------*/

/*********************************** 全局变量 **********************************/

/*********************************** 接口函数 **********************************/
int scull_open(struct inode *inode, struct file *filp);
int scull_release(struct inode *inode, struct file *filp);

ssize_t scull_read(struct file *filp, char __user *buff, size_t count, loff_t *offp);
ssize_t scull_write(struct file *filp, const char __user *buff, size_t count, loff_t *offp);


/* 由于需要使用接口 故放在最末端 */
struct file_operations scull_fops = {
    .owner      = THIS_MODULE,
    .open       = scull_open,
    .release    = scull_release,
    .read       = scull_read,
    .write      = scull_write,
};


#endif // #ifndef _SCULL_H_


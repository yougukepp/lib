/*****************************************************************
 * Copyright(c) 2012, 武汉中原电子集团 应用电子研发中心
 * All rights reserved.
 * *
 * 文件名称:
 *
 * 摘要:
 *
 * 作者:PengPeng <yougukepp@gmail.com>
 *
 * 完成日期:
 *****************************************************************/
/*--------------------------- 预处理区 --------------------------*/
#ifndef __QG_CONFIG_H__
#define __QG_CONFIG_H__

/***************************** 头文件 ****************************/
#include "HyConfig.h"

/***************************** 宏定义 ****************************/
#define         QG_PI                          (HY_PI)
#define         QG_INFINITE_SIMAL              (HY_INFINITE_SIMAL)

#define         QG_SHADER_SRC_BUF              (4096)
#define         QG_CIRCLE_LINE_NUM             (100)
#define         QG_CIRCLE_ANGLE_PER_LINE       (2 * QG_PI / QG_CIRCLE_LINE_NUM)

#define         QG_RUNNING_FRAME_NUMS           (20000)

/* 调试开关 */
//#define __DEBUG_QG_TRACE_DRAWED_POINTS__
#define __DEBUG_QG_PRINT_FPS__

/**************************** 类型定义 ***************************/





/*-------------------------- 接口声明区 -------------------------*/

/**************************** 全局变量 ***************************/


/**************************** 接口函数 ***************************/

#endif



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
#ifndef __GIS_CONFIG_H__
#define __GIS_CONFIG_H__

/***************************** 头文件 ****************************/
#include "HyConfig.h"

/***************************** 宏定义 ****************************/
#define         GIS_PI                          (HY_PI)
#define         GIS_INFINITE_SIMAL              (HY_INFINITE_SIMAL)

#define         GIS_SHADER_SRC_BUF              (4096)
#define         GIS_CIRCLE_LINE_NUM             (1000)
#define         GIS_CIRCLE_ANGLE_PER_LINE       (2 * GIS_PI / GIS_CIRCLE_LINE_NUM)

/* 调试开关 */
//#define __DEBUG_GIS_TRACE_DRAWED_POINTS__
#define __DEBUG_GIS_TRACE_DRAWED_FRAME__

/**************************** 类型定义 ***************************/





/*-------------------------- 接口声明区 -------------------------*/

/**************************** 全局变量 ***************************/


/**************************** 接口函数 ***************************/

#endif



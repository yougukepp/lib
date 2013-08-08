#ifndef __HY_DATA_TYPE_H__
#define __HY_DATA_TYPE_H__

#ifndef HY_FALSE
#define HY_FALSE (0)
#endif

#ifndef HY_TRUE
#define HY_TRUE (!(HY_FALSE))
#endif

#ifndef HY_SUCCESSED
#define HY_SUCCESSED (0)
#endif

#ifndef HY_FAILED
#define HY_FAILED (-1)
#endif

typedef char HyC;
typedef unsigned char HyU8;
typedef unsigned int HyU32;
typedef double HyFloat;
typedef long HyU64;

typedef void (*HyCallBackFunc)(void);
typedef void (*HyCallBackFuncWithPara)(void *pPara); 

typedef void (*HyUdpServerDealCallBackFunc)(HyU8 *pBuf, HyU32 len);

#endif

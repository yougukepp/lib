#include "HyInterface.h"

static HyU32 TestHyTimer(void);
static void timerCallBackFunc(void *pPara);

static void UdpServerDeal(HyU8 *pBuf, HyU32 len);
static HyU32 TestUdp(void);

const HyU32 gUdpBufSize = 200;
static HyU32 gUdpDealled = HY_FALSE;

int main(int argc, char *argv[])
{
    printf("开始测试.\n");
    printf("TestHyTimer:%s.\n", (HY_SUCCESSED == TestHyTimer()) ? ("成功") : ("失败"));
    printf("TestUdp:%s.\n", (HY_SUCCESSED == TestUdp()) ? ("成功") : ("失败"));
    printf("结束测试.\n");

    fflush(stdout);
    return 0;
}

/* 计数值加1 */
static void timerCallBackFunc(void *pPara)
{
    HyU32 *p = NULL;
    p = (HyU32 *)pPara;
    /* TODO: 需要写时锁? */
    *p = (*p) + 1;
}

HyU32 TestHyTimer(void)
{ 
    HyU32 rst = HY_FAILED;

    HyCallBackFuncWithPara pTimerCallBackFunc = NULL;
    HyU32 *pTimerCallBackFuncPara = NULL;
    HyTimer *pTimer = new HyTimer();
    pTimerCallBackFunc = timerCallBackFunc;
    HyU32 tickCount = 0;
    pTimerCallBackFuncPara = &tickCount;
    HyU32 sleepTime = 1;                                /* s */
    HyU32 intervalTime = 1;                             /* ms */

    pTimer->SetInterval(intervalTime);
    pTimer->SetCallBackFunc(pTimerCallBackFunc, pTimerCallBackFuncPara);
    pTimer->Start();

    sleep(sleepTime);
    if(0 != tickCount)
    {
        rst = HY_SUCCESSED;
    }

    pTimer->Stop();

    return rst;
}

static void UdpServerDeal(HyU8 *pBuf, HyU32 len)
{ 
    if(gUdpBufSize != len)
    {
        printf("丢包\n");
        return;
    }

    for(HyU32 i=0; i<gUdpBufSize; i++)
    {
        if((HyU8)(0x000000FF & i) != pBuf[i])
        {
            printf("第%d字节传错, 预期:0x%02x, 实际:0x%02x\n", i, (HyU8)(0x000000FF & i), pBuf[i]);
            return;
        }
    } 
    
    fflush(stdout);
    gUdpDealled = HY_TRUE;
}

HyU32 TestUdp(void)
{ 
    HyU32 port = 0;
    HyUdpServerDealCallBackFunc pDealFunc = NULL;

    port = 5802;
    pDealFunc = UdpServerDeal;

    HyUdpServer *pServer = new HyUdpServer(port);
    pServer->SetDealFunc(pDealFunc);
    pServer->Start(1);

    const HyC *ip = NULL;
    HyU8 pBuf[gUdpBufSize];

    ip = "127.0.0.1";
    for(HyU32 i=0; i<gUdpBufSize; i++)
    {
        pBuf[i] = (HyU8)(0x000000FF & i);
    }

    HyUdpClient *pClient = new HyUdpClient(ip, port);
    pClient->Send(pBuf, gUdpBufSize);

    while(HY_TRUE != gUdpDealled)
    {
        sleep(1);
    }

    return HY_SUCCESSED;
}


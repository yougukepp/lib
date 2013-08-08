#include "HyInterface.h"

static HyU32 TestHyTimer(void);
static void timerCallBackFunc(void *pPara);

static HyU32 TestUdp(void);

int main(int argc, char *argv[])
{
    HyU32 rst = HY_FAILED;

    printf("开始测试.\n");

    /*
    rst = TestHyTimer();
    printf("TestHyTimer: %s.\n", (HY_SUCCESSED == rst) ? ("成功") : ("失败"));
    */

    rst = TestUdp();
    printf("TestUdp: %s.\n", (HY_SUCCESSED == rst) ? ("成功") : ("失败"));

    printf("结束测试.\n");

    fflush(stdout);
    return 0;
}

/* 计数值加1 */
static void timerCallBackFunc(void *pPara)
{
    HyU32 *p = NULL;
    p = (HyU32 *)pPara;
    /* TODO: 需要写时锁 */
    *p = (*p) + 1;
}

HyU32 TestHyTimer(void)
{ 
    HyCallBackFuncWithPara pTimerCallBackFunc = NULL;
    HyU32 *pTimerCallBackFuncPara = NULL;
    HyTimer *pTimer = new HyTimer();
    pTimerCallBackFunc = timerCallBackFunc;
    HyU32 tickCount = 0;
    pTimerCallBackFuncPara = &tickCount;
    HyU32 tickMax = 5;
    HyU32 sleepTime = 1000;                             /* ms */

    pTimer->SetInterval(1000);
    pTimer->SetCallBackFunc(pTimerCallBackFunc, pTimerCallBackFuncPara);
    pTimer->Start();

    while(tickCount < tickMax)
    {
        printf("TestHyTimer: tickCount:%d.\n", tickCount);
        sleep(sleepTime / 999.0);
    }

    pTimer->Stop();

    return HY_SUCCESSED;
}

HyU32 TestUdp(void)
{ 
    HyU32 port = 5802;
    HyUdpServer *pServer = new HyUdpServer(port);

    pServer->Start(1);

    return HY_SUCCESSED;
}


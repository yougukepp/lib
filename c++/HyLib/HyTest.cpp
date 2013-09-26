#include "HyInterface.h"

static HyU32 TestHyTimer(void);
static void timerCallBackFunc(void *pPara);

static void UdpServerDeal(HyUdpPackage &pkg);

static HyU32 TestUdp(void);

const HyU32 gUdpBufSize = 200;

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
    /* TODO: 使用timer时需要写时锁 */
    *p = (*p) + 1;

    printf("完成周期操作%s:%d.\n", __func__, *p);
    fflush(stdout);
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
    HyU32 sleepTime = 2000;                             /* us */
    HyU32 intervalTime = 1;                             /* ms */

    pTimer->SetInterval(intervalTime);
    pTimer->SetCallBackFunc(pTimerCallBackFunc, pTimerCallBackFuncPara);
    pTimer->Start();

    usleep(sleepTime);
    if(0 != tickCount)
    {
        rst = HY_SUCCESSED;
    }

    pTimer->Stop();

    return rst;
}

static void UdpServerDeal(HyUdpPackage &pkg)
{ 
    HyC ipBuf[20];
    HyU16 port = 0;
    HyU8 *pBuf = NULL;
    size_t len = 0;

    pkg.GetIp(ipBuf, 20);
    pkg.GetPort(port);
    pBuf = pkg.GetBuf();
    len = pkg.GetBufSize();

    printf("开始处理接收%s:%d(0x%04x)发送的%ld字节.\n", ipBuf, port, port, len);
    fflush(stdout);

    if(gUdpBufSize != len)
    {
        printf("丢包, gUdpBufSize=%d, pkg.GetBufSize()=%ld\n", gUdpBufSize, len);
        fflush(stdout);
        return;
    }

    for(HyU32 i=0; i<len; i++)
    {
        if((HyU8)(0x000000FF & i) != pBuf[i])
        {
            printf("第%d字节传错, 预期:0x%02x, 实际:0x%02x\n", i, (HyU8)(0x000000FF & i), pBuf[i]);
            fflush(stdout);
            return;
        }
    } 
}

HyU32 TestUdp(void)
{ 
    HyU32 sleepTime = 2000;                             /* us */
    HyU16 port = 0;
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

    HyUdpClient *pClient = new HyUdpClient(); 
    
    HyUdpPackage pkg(HyUdpPackageSend,
            pBuf, gUdpBufSize,
            ip, port);

    pClient->Send(pkg); 
    usleep(sleepTime);

    pClient->Send(pkg); 
    usleep(sleepTime);

    pServer->Stop(1);

    return HY_SUCCESSED;
}


#include "HyTimer.h"

static void *ThreadLoop(void *arg);

HyTimer::HyTimer(void)
{
    m_interval = 0;
    m_callBackFunc = NULL;
} 

HyTimer::~HyTimer(void)
{
    Stop();
    m_callBackFunc = NULL;
    m_interval = 0;
}

void HyTimer::SetInterval(int ms)
{
    m_interval = ms;
}

void HyTimer::SetCallBackFunc(HyCallBackFuncWithPara callBackFunc, void *pPara)
{
    m_callBackFunc = callBackFunc;
    m_pCallBackPara = pPara;
} 

void HyTimer::Start(void)
{
    int rst = 0;
    m_running = true;
    rst = pthread_create(&m_tid, NULL, ThreadLoop, this);
    assert(0 == rst);
}

void HyTimer::Stop(void)
{
    m_running = false;
    pthread_join(m_tid, NULL);
} 

bool HyTimer::Running(void)
{
    return m_running;
}

void HyTimer::CallBackFunc(void)
{
    m_callBackFunc(m_pCallBackPara);
}

int HyTimer::Interval(void)
{
    return m_interval;
}

static void *ThreadLoop(void *arg)
{
    assert(NULL != arg);

    HyTimer *pTimer = (HyTimer *)arg;

    useconds_t us = 0;
    us = 1000 * pTimer->Interval();

    while(pTimer->Running())
    {
        pTimer->CallBackFunc();
        usleep(us);
    }
    pthread_exit(NULL);
}


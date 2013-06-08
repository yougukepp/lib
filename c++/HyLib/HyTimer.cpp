#include "HyTimer.h"

static void *ThreadLoop(void *arg);

HyTimer::HyTimer(void)
{
    m_interval = 0;
    m_callBackFunc = NULL;
}

void HyTimer::SetInterval(int ms)
{
    m_interval = ms;
}

void HyTimer::SetCallBackFunc(HyCallBackFunc callBackFunc)
{
    m_callBackFunc = callBackFunc;
} 

void HyTimer::Start(void)
{
    int rst = 0;
    rst = pthread_create(&m_tid, NULL, ThreadLoop, this);
    assert(0 == rst);
    m_running = true;
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

HyCallBackFunc HyTimer::CallBackFunc(void)
{
    return m_callBackFunc;
}

int HyTimer::Interval(void)
{
    return m_interval;
}

static void *ThreadLoop(void *arg)
{
    assert(NULL != arg);
    HyTimer *pTimer = (HyTimer *)arg;

    while(pTimer->Running())
    {
        pTimer->CallBackFunc();
        sleep(pTimer->Interval());
    }
    pthread_exit(NULL);
}


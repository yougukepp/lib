#ifndef __HY_TIMER_H__
#define __HY_TIMER_H__

#include "HyConfig.h"
#include "HyHeader.h"

class HyTimer
{
public:
    HyTimer(void);
    void SetInterval(int ms);
    void SetCallBackFunc(HyCallBackFuncWithPara callBackFunc, void *pPara);
    void Start(void);
    void Stop(void); 

    bool Running(void);
    void CallBackFunc(void);
    int Interval(void);

private:
    int m_interval;
    HyCallBackFuncWithPara m_callBackFunc;
    void *m_pCallBackPara;

    pthread_t m_tid;
    bool m_running;
};

#endif


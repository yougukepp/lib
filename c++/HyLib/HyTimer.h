#ifndef __HY_TIMER_H__
#define __HY_TIMER_H__

#include "HyHeader.h"

class HyTimer
{
public:
    HyTimer(void);
    void SetInterval(int ms);
    void SetCallBackFunc(HyCallBackFunc callBackFunc);
    void Start(void);
    void Stop(void); 

    bool Running(void);
    HyCallBackFunc CallBackFunc(void);
    int Interval(void);

private:
    int m_interval;
    HyCallBackFunc m_callBackFunc;
    pthread_t m_tid;
    bool m_running;
};

#endif


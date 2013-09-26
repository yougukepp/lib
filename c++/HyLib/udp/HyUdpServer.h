#ifndef __HY_UDP_SERVER_H__
#define __HY_UDP_SERVER_H__

#include "HyConfig.h"
#include "HyHeader.h"
#include "HyUdpPackage.h"

class HyUdpPackage;
class HyUdpServer;

class HyUdpServer
{
public:
    HyUdpServer(HyU32 port);
    virtual ~HyUdpServer();

    void Start(void);
    void Stop(void);
    void SetDealFunc(HyUdpServerDealCallBackFunc pFunc);

public:                         /* 仅供静态函数使用 */
    int  m_sockFd;
    bool m_running;
    std::vector<HyUdpPackage> m_buf;
    HyUdpServerDealCallBackFunc m_pFunc;

    void Lock(void);
    void UnLock(void);

protected:

    HyU32 InitSocket(void);
    void DeinitSocket(void);
    HyU32 BindToPort(int port);
    void SetSysUdpBuf(HyU32 size);
    
    void InitMutex(void);
    void DeinitMutex(void);

private:
    pthread_t                   m_tRecv;
    pthread_t                   m_tDeal;

    pthread_mutex_t             m_mutex;
};

#endif

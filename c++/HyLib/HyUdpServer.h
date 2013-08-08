#ifndef __HY_UDP_SERVER_H__
#define __HY_UDP_SERVER_H__

#include "HyConfig.h"
#include "HyHeader.h"

class HyUdpServer;

/* TODO: 封装为类 */
typedef struct
{
    HyU8 buf[HY_UDP_SERVER_RECV_PKG_MAX_LEN];
    HyU32 len;
}TAG_HY_UDP_PKG;

/* TODO:封装为类 */
typedef struct
{
    HyUdpServer*        obj;
    HyU32               obj_id;
}TAG_HY_THREAD_OBJ;

/* TODO:加入停止功能 */
class HyUdpServer
{
public:
    HyUdpServer(HyU32 port);
    virtual ~HyUdpServer();

    void Start(HyU32 obj_id);
    void Stop(HyU32 obj_id);

public:                         /* 仅供静态函数使用 */
    int  m_sockFd;
    std::vector<TAG_HY_UDP_PKG> m_buf;
    HyUdpServerDealCallBackFunc m_pFunc;

    void Lock(void);
    void UnLock(void);

    void SetDealFunc(HyUdpServerDealCallBackFunc pFunc);

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
private:
    TAG_HY_THREAD_OBJ           m_self;
};

#endif

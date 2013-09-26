#ifndef __HY_UDP_CLIENT_H__
#define __HY_UDP_CLIENT_H__

#include "HyConfig.h"
#include "HyHeader.h"

#include "HyUdpPackage.h"
class HyUdpPackage;

class HyUdpClient
{
public: 
    HyUdpClient(void);
    void Send(HyUdpPackage &pkg);

protected: 
    HyU32 InitSocket(void);
    void InitAddr(HyUdpPackage &pkg);

private:
    int m_sockFd;
};

#endif

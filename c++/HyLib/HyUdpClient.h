#ifndef __HY_UDP_CLIENT_H__
#define __HY_UDP_CLIENT_H__

#include "HyHeader.h"

class HyUdpClient
{
public: 
    HyUdpClient(const HyC *ip, HyU32 port);
    void Send(const HyU8 *pBuf, HyU32 len);

protected: 
    HyU32 InitSocket(void);
    void InitAddr(const HyC *ip, HyU32 port);

private:
    int m_sockFd;
    struct sockaddr_in m_addr;
};

#endif

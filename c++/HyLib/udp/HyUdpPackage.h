#ifndef __HY_UDP_PACKAGE_H__
#define __HY_UDP_PACKAGE_H__

#include "HyConfig.h"
#include "HyHeader.h"

class HyUdpPackage
{
public:
    HyUdpPackage(HyU8 *buf, int bufSize, const char *ip, int port);
    virtual ~HyUdpPackage(void);

    HyU8 *GetBuf(void);
    size_t GetBufSize(void);
    struct sockaddr_in *GetAddrPtr(void);
    socklen_t GetAddrLen(void);

    /* for debug */
    void print(void); 
    
    /*
    enum HyUdpPackageTypeEnum
    {
        Send,
        Recv
    };
    */

public:

protected:

private:

private:
    HyUdpPackage();

    const char *m_addr;
    short m_port;
    std::vector<HyU8> m_data;
};

#endif


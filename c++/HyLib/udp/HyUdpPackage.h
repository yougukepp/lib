#ifndef __HY_UDP_PACKAGE_H__
#define __HY_UDP_PACKAGE_H__

#include "HyConfig.h"
#include "HyHeader.h" 

enum HyUdpPackageTypeEnum
{
    HyUdpPackageSend,
    HyUdpPackageRecv
};

class HyUdpPackage
{
public:
    HyUdpPackage(enum HyUdpPackageTypeEnum type, HyU8 *buf, HyU32 bufSize, const HyU8 *ip, HyU16 port);
    virtual ~HyUdpPackage(void);

    HyU8 *GetBuf(void);
    size_t GetBufSize(void);

    /*
    struct sockaddr_in *GetAddrPtr(void);
    socklen_t GetAddrLen(void);
    */

    /* for debug */
    void print(void); 
    
public:

protected:

private:

private:
    HyUdpPackage();

    enum HyUdpPackageTypeEnum m_type;
    const HyU8 *m_addr;
    HyU16 m_port;
    std::vector<HyU8> m_data;
};

#endif

﻿#ifndef __HY_UDP_PACKAGE_H__
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
    HyUdpPackage(enum HyUdpPackageTypeEnum type, HyU8 *buf, HyU32 bufSize, const HyC *ip, HyU16 port);
    virtual ~HyUdpPackage(void);

    HyU8 *GetBuf(void);
    size_t GetBufSize(void);

    /* 尽可能将指针换为引用 */
    void GetAddrPtr(struct sockaddr_in *pAddr);
    void GetIp(HyC *pIp, Hy32 len);
    void GetPort(HyU16 &port);

    /* for debug */
    void DebugOut(void);
    
public:

protected:

private:

private:
    HyUdpPackage();

    enum HyUdpPackageTypeEnum m_type;
    const HyC *m_addr;
    HyU16 m_port;
    std::vector<HyU8> m_data;
};

#endif

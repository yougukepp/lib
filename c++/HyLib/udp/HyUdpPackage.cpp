#include "HyUdpPackage.h"

HyUdpPackage::HyUdpPackage(enum HyUdpPackageTypeEnum type, HyU8 *buf, HyU32 bufSize, const HyC *ip, HyU16 port)
{
    HyU32 i = 0;
    assert((HyUdpPackageSend == type) || (HyUdpPackageRecv == type));
    assert(NULL != ip);
    assert(port >= 0);

    m_type = type;
    m_addr = ip;
    m_port = port;

    m_data.clear();
    for(i=0; i<bufSize; i++)
    {
        m_data.push_back(buf[i]);
    }
}

void HyUdpPackage::DebugOut(void)
{
    printf("%s方信息%s:%d(0x%04x),字节数:%ld.\n", (HyUdpPackageRecv == m_type) ? "发送" : "接收",
            m_addr, m_port, m_port, m_data.size());
    fflush(stdout);
}


HyU8 *HyUdpPackage::GetBuf(void)
{
    return m_data.data();
}

size_t HyUdpPackage::GetBufSize(void)
{
    return m_data.size();
}

void HyUdpPackage::GetAddrPtr(struct sockaddr_in *pAddr)
{ 
    bzero(pAddr, sizeof(struct sockaddr_in));
    pAddr->sin_family = AF_INET;
    pAddr->sin_addr.s_addr = inet_addr(m_addr);
    pAddr->sin_port = htons(m_port);
}

HyUdpPackage::~HyUdpPackage(void)
{
}


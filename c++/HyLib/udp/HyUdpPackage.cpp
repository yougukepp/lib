#include "HyUdpPackage.h"

HyUdpPackage::HyUdpPackage(enum HyUdpPackageTypeEnum type, HyU8 *buf, HyU32 bufSize, const HyU8 *ip, HyU16 port)
{
    Hy32 i = 0;
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

#ifdef __DEBUG_HY_UDP_PACKAGE__
    printf("%s方信息%s:%d(0x%04x),字节数:%d.\n", (HyUdpPackageRecv == type) ? "发送" : "接收",
            m_addr, m_port, m_port, bufSize);
    fflush(stdout);
#endif

}

HyU8 *HyUdpPackage::GetBuf(void)
{
    return m_data.data();
}

size_t HyUdpPackage::GetBufSize(void)
{
    return m_data.size();
}

HyUdpPackage::~HyUdpPackage(void)
{
    ;
}


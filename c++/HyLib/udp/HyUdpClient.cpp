#include "HyUdpClient.h"

HyUdpClient::HyUdpClient(void)
{
    ;
}

void HyUdpClient::Send(HyUdpPackage &pkg)
{
    /* 建立udp socket */
    Hy32 sockFd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if(-1 != sockFd)
    {
#ifdef __DEBUG_HY_UDP_CLIENT__
        printf("HyUdpClient 初始化套接字成功.\n");
        fflush(stdout);
#endif
    }
    else
    {
        printf("HyUdpClient 初始化套接字失败.\n");
        fflush(stdout);
        return;
    }

    int rst = 0;
    struct sockaddr_in addr;
    /* 获取发送内容 */
    const HyU8 *pBuf = pkg.GetBuf();
    size_t len = pkg.GetBufSize();
    /* 获取地址 */
    pkg.GetAddrPtr(&addr);

    rst = sendto(sockFd, pBuf, len, 0, (struct sockaddr *)&addr, sizeof(addr));
    assert(rst >= 0);

#ifdef __DEBUG_HY_UDP_CLIENT__
    pkg.DebugOut();
#endif

    close(sockFd);
}


#include "HyUdpClient.h"

/*
 * TODO: 初始化时 空参数列表
 *       发送时传递 HyUdpPackage
 * */
HyUdpClient::HyUdpClient(const HyC *ip, HyU32 port)
{
    if(HY_SUCCESSED == InitSocket())
    {
#ifdef __DEBUG_HY_UDP_SERVER__
        printf("HyUdpClient 初始化套接字成功.\n");
#endif
        InitAddr(ip, port);
#ifdef __DEBUG_HY_UDP_SERVER__
        printf("HyUdpClient设置地址成功.\n");
#endif
    }
    else
    {
#ifdef __DEBUG_HY_UDP_SERVER__
        printf("HyUdpClient 初始化套接字失败.\n");
#endif
    }
    fflush(stdout);
}

void HyUdpClient::Send(const HyU8 *pBuf, HyU32 len)
{
    int rst = 0;
    rst = sendto(m_sockFd, pBuf, len, 0, (struct sockaddr *)&m_addr, sizeof(m_addr));
    assert(rst >= 0);
}

HyU32 HyUdpClient::InitSocket(void)
{
    /* 建立udp socket */
    m_sockFd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if(-1 != m_sockFd)
    {
        return HY_SUCCESSED;
    }
    else
    {
        return HY_FAILED;
    }
}

void HyUdpClient::InitAddr(const HyC *ip, HyU32 port)
{ 
    bzero(&m_addr, sizeof(struct sockaddr_in));
    m_addr.sin_family = AF_INET;
    m_addr.sin_addr.s_addr = inet_addr(ip);
    m_addr.sin_port = htons(port);
}


#include "HyUdpServer.h"

/* 接收线程 */
void* threadRecvLoop(void *argv);
/* 处理线程 */
void* threadDealLoop(void *argv);
static long gTotalBytes;

HyUdpServer::HyUdpServer(HyU32 port)
{
    m_sockFd = -1;
    m_running = false;
    m_buf.clear();
    InitMutex();

    if (HY_SUCCESSED == InitSocket())                           /* 初始化套接字 */
    {
#ifdef __DEBUG_HY_UDP_SERVER__
        printf("初始化UDP服务器OK.\n");
#endif
        if (HY_SUCCESSED == BindToPort(port))                   /* 绑定监听端口 */
        {
            SetSysUdpBuf(10 * 1024 * 1024);                     /* 设置该Socket 系统 BUF大小 10M */
#ifdef __DEBUG_HY_UDP_SERVER__
            printf("UDP服务器绑定至端口:%d.\n", port);
#endif
        }
        else
        {
            DeinitSocket();
#ifdef __DEBUG_HY_UDP_SERVER__
            printf("UDP服务器绑定至端口:%d失败.\n", port);
#endif
        }
    }
    else
    {
#ifdef __DEBUG_HY_UDP_SERVER__
        printf("初始化UDP服务器失败!\n");
#endif
    }
#ifdef __DEBUG_HY_UDP_SERVER__
    fflush(stdout);
#endif
}

HyUdpServer::~HyUdpServer()
{
    DeinitSocket();
    m_buf.clear();
    DeinitMutex();
} 

void HyUdpServer::SetDealFunc(HyUdpServerDealCallBackFunc pFunc)
{
    assert(NULL != pFunc);
    m_pFunc = pFunc;
}

void HyUdpServer::InitMutex(void)
{
    int rst = 0;
    rst = pthread_mutex_init(&m_mutex, NULL);
    assert(0 == rst);
}

void HyUdpServer::DeinitMutex(void)
{
    int rst = 0;
    rst = pthread_mutex_destroy(&m_mutex);
    assert(0 == rst);
}

void HyUdpServer::Lock(void)
{
    int rst = 0;
    rst = pthread_mutex_lock(&m_mutex);         /* 阻塞 */
    assert(0 == rst);
}

void HyUdpServer::UnLock(void)
{
    int rst = 0;
    rst = pthread_mutex_unlock(&m_mutex);
    assert(0 == rst);
}

HyU32 HyUdpServer::InitSocket(void)
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

void HyUdpServer::DeinitSocket(void)
{
    int rst = 0;
    assert(-1 != m_sockFd);
    rst = close(m_sockFd);
    assert(0 == rst);
}

HyU32 HyUdpServer::BindToPort(int port)
{
    int rst = 0;
    struct sockaddr_in servAddr;
    /* 设置address */
    bzero(&servAddr, sizeof(struct sockaddr_in));
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(port);

    /* INADDR_ANY表示不管是哪个网卡接收到数据，只要目的端口是SERV_PORT，就会被该应用程序接收到 */
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    /* 绑定socket */
    rst = bind(m_sockFd, (struct sockaddr *)&servAddr, sizeof(servAddr));
    if(0 != rst)
    {
        return HY_FAILED;
    }
    else
    {
        return HY_SUCCESSED;
    }
}

void HyUdpServer::SetSysUdpBuf(HyU32 size)
{
    int rst = 0;
    rst = setsockopt(m_sockFd, SOL_SOCKET, SO_RCVBUF, (const char*)&size, sizeof(int));
    assert(0 == rst);
}

void HyUdpServer::Start(HyU32 obj_id)
{
    m_self.obj = this;
    m_self.obj_id = obj_id;

    m_running = true;
    pthread_create(&m_tRecv, NULL, threadRecvLoop, (void*)(&m_self));
    pthread_create(&m_tDeal, NULL, threadDealLoop, (void*)(&m_self));
} 

void HyUdpServer::Stop(HyU32 obj_id)
{
    m_running = false;
    pthread_join(m_tDeal, NULL);
    pthread_join(m_tRecv, NULL);
}

void* threadRecvLoop(void *argv)
{
    HyU8 buf[100 * 1024];
    TAG_HY_THREAD_OBJ* to = (TAG_HY_THREAD_OBJ*)argv;
    HyUdpServer *obj = to->obj;

    //assert((obj->m_sockFd) >= 0);

    struct sockaddr_in clientAddr;
    int len = 0;
    len = sizeof(clientAddr);

#ifdef __DEBUG_HY_UDP_SERVER__
    printf("Udp接收线程启动...\n");
    fflush(stdout);
#endif

    while(obj->m_running)
    {
        Hy32 recvNum = recvfrom(obj->m_sockFd,
                buf,
                HY_UDP_SERVER_RECV_PKG_MAX_LEN,
                MSG_DONTWAIT, /* 0 */
                (struct sockaddr *)&clientAddr,
                (socklen_t *)&len);

        if(-1 == recvNum) /* 本次未收到数据 */
        {
            if((EAGAIN == errno)
            || (EWOULDBLOCK == errno))
            {
                /* 阻塞延迟1ms 提升性能
                 * buf 为100k <==> 1ms
                 * ====> 最大吞吐率 100M/s */
                usleep(1000);
                continue;
            }
        }
        assert(recvNum > 0);

        HyU16 port = ntohs(clientAddr.sin_port);
        const HyC *addr = (const HyC *)inet_ntoa(clientAddr.sin_addr);

        HyUdpPackage pkg(HyUdpPackageRecv,
                buf, recvNum,
                addr, port);

#ifdef __DEBUG_HY_UDP_SERVER__
        pkg.DebugOut();
#endif

        obj->Lock();
        (obj->m_buf).push_back(pkg);
        obj->UnLock();

        gTotalBytes += recvNum;
    }

    return NULL;
}

void* threadDealLoop(void *argv)
{
    TAG_HY_THREAD_OBJ* to = (TAG_HY_THREAD_OBJ*)argv;
    HyUdpServer* obj = to->obj;

    HyU32 i = 0;
    HyU32 iMax = 0;
    int rst = 0;
    HyFloat passed_seconds = 0;
    HyU64 usec = 0;
    struct timeval last;
    struct timeval now; 

#ifdef __DEBUG_HY_UDP_SERVER__
    printf("处理线程启动...\n");
    fflush(stdout);
#endif

    HyU32 secCount = 0;

    while(obj->m_running)
    {

        rst = gettimeofday(&now, NULL);
        assert(0 == rst); 

        passed_seconds = difftime(now.tv_sec, last.tv_sec); 
        usec = now.tv_usec - last.tv_usec; 
        passed_seconds = 1.0 * passed_seconds + usec * 0.000001; 

        if(passed_seconds >= 2.0)
        {
            secCount++;
#ifdef __DEBUG_HY_UDP_SERVER__
            printf("%ld 字节 %f Bytes/s\n", gTotalBytes, 1.0 * gTotalBytes / secCount);
            fflush(stdout);
#endif
            rst = gettimeofday(&last, NULL);
            assert(0 == rst); 
        }

        /* 解析 */ 
        obj->Lock();
        assert(NULL != obj->m_pFunc);
        iMax = (obj->m_buf).size();
        for(i=0;i<iMax;i++)
        {
            obj->m_pFunc((obj->m_buf)[i]);
        }
        (obj->m_buf).clear();
        obj->UnLock();
    }

#ifdef __DEBUG_HY_UDP_SERVER__
    printf("\n总计:\n     %ld 字节 %f Bytes/s\n", gTotalBytes, 1.0 * gTotalBytes / secCount);
    fflush(stdout);
#endif

    return NULL;
}


#include "HyUdpServer.h"

/* �����߳� */
void* threadRecvLoop(void *argv);
/* �����߳� */
void* threadDealLoop(void *argv);
static long gTotalBytes;

HyUdpServer::HyUdpServer(HyU32 port)
{
    m_sockFd = -1;
    m_buf.clear();
    InitMutex();

    if (HY_SUCCESSED == InitSocket())                           /* ��ʼ���׽��� */
    {
        printf("��ʼ��UDP������OK!\n");
        if (HY_SUCCESSED == BindToPort(port))                   /* �󶨼����˿� */
        {
            SetSysUdpBuf(10 * 1024 * 1024);                     /* ���ø�Socket ϵͳ BUF��С 10M */
            printf("UDP�����������˿�:%d.\n", port);
        }
        else
        {
            DeinitSocket();
            printf("UDP�����������˿�:%dʧ��.\n", port);
        }
    }
    else
    {
        printf("��ʼ��UDP������ʧ��!\n");
    }
    fflush(stdout);
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
    HyU32 rst = 0;
    rst = pthread_mutex_init(&m_mutex, NULL);
    assert(0 == rst);
}

void HyUdpServer::DeinitMutex(void)
{
    HyU32 rst = 0;
    rst = pthread_mutex_destroy(&m_mutex);
    assert(0 == rst);
}

void HyUdpServer::Lock(void)
{
    HyU32 rst = 0;
    rst = pthread_mutex_lock(&m_mutex);         /* ���� */
    assert(0 == rst);
}

void HyUdpServer::UnLock(void)
{
    HyU32 rst = 0;
    rst = pthread_mutex_unlock(&m_mutex);
    assert(0 == rst);
}

HyU32 HyUdpServer::InitSocket(void)
{
    /* ����udp socket */
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
    HyU32 rst = 0;
    assert(-1 != m_sockFd);
    rst = close(m_sockFd);
    assert(0 == rst);
}

HyU32 HyUdpServer::BindToPort(int port)
{
    HyU32 rst = 0;
    struct sockaddr_in servAddr;
    /* ����address */
    bzero(&servAddr, sizeof(struct sockaddr_in));
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(port);

    /* INADDR_ANY��ʾ�������ĸ��������յ����ݣ�ֻҪĿ�Ķ˿���SERV_PORT���ͻᱻ��Ӧ�ó�����յ� */
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    /* ��socket */
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
    HyU32 rst = 0;
    rst = setsockopt(m_sockFd, SOL_SOCKET, SO_RCVBUF, (const char*)&size, sizeof(int));
    assert(0 == rst);
}

void HyUdpServer::Start(HyU32 obj_id)
{
    m_self.obj = this;
    m_self.obj_id = obj_id;

    pthread_create(&m_tRecv, NULL, threadRecvLoop, (void*)(&m_self));
    pthread_create(&m_tDeal, NULL, threadDealLoop, (void*)(&m_self));
} 

/* TODO */
void Stop(HyU32 obj_id)
{
    ;
}

void* threadRecvLoop(void *argv)
{
    HyU8 buf[2048];
    TAG_HY_THREAD_OBJ* to = (TAG_HY_THREAD_OBJ*)argv;
    HyUdpServer *obj = to->obj;

    //assert((obj->m_sockFd) >= 0);

    struct sockaddr_in clientAddr;
    HyU32 len = 0;
    printf("begin threadRecvLoop.\n");
    fflush(stdout);

    while(true)
    {
        HyU8 recvNum = recvfrom(obj->m_sockFd,
                buf,
                HY_UDP_SERVER_RECV_PKG_MAX_LEN,
                0/* MSG_DONTWAIT*/,
                (struct sockaddr *)&clientAddr,
                (socklen_t *)&len);

        assert(recvNum > 0);

        HyU32 i = 0;
        HyU32 len = 0;
        TAG_HY_UDP_PKG pkg;
        len = recvNum;
        for(i=0;i<len;i++)
        {
            pkg.buf[i] = buf[i];
        }
        pkg.len = len;


        /* TODO:lock*/
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
    HyU32 rst = 0;
    HyFloat passed_seconds = 0;
    HyU64 usec = 0;
    struct timeval last;
    struct timeval now; 

    printf("begin threadDealLoop.\n");
    fflush(stdout);

    HyU32 secCount = 0;

    while(true)
    {

        rst = gettimeofday(&now, NULL);
        assert(0 == rst); 

        passed_seconds = difftime(now.tv_sec, last.tv_sec); 
        usec = now.tv_usec - last.tv_usec; 
        passed_seconds = 1.0 * passed_seconds + usec * 0.000001; 

        if(passed_seconds >= 2.0)
        {
            secCount++;
            printf("total %ld BYTE %f Bytes/s\n", gTotalBytes, 1.0 * gTotalBytes / secCount);
            fflush(stdout);
            rst = gettimeofday(&last, NULL);
            assert(0 == rst); 
        }

        /* ���� */
        assert(NULL != obj->m_pFunc);

        iMax = (obj->m_buf).size();
        for(i=0;i<iMax;i++)
        {
            obj->m_pFunc((obj->m_buf)[i].buf, (obj->m_buf)[i].len);
        }

        obj->Lock();
        (obj->m_buf).clear();
        obj->UnLock();
    }
}


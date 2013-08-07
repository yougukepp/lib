#include "RadadrUdpServer.h"

/*仅处理回波信息接收*/
void* threadRecvLoop(void *argv);
void* threadDealLoop(void *argv);
static long gTotalBytes;

CRadadrUdpServer::CRadadrUdpServer(int port)
{
    m_bMutex = initMutex();
    m_SockFd = -1;
    m_RecvBufSize = 4096;
    m_RecvBuf = new unsigned char[m_RecvBufSize];
    if (initSocket())								/* 初始化套接字 */
    {
        printf("init UDP server ok!\n");
        if (bindToPort(port))                                                   /* 绑定监听端口 */
        {
            setSysUdpBuf(10 * 1024 * 1024);                                     /* 设置该Socket 系统 BUF大小 */
            printf("init UDP server bind port %d ok!\n", port);
            start(1);
        }
        else
        {
            deinitSocket();
            printf("init UDP server bind port %d error!\n", port);
        }
    }
    else
    {
        printf("init UDP server error!\n");
    }
}

CRadadrUdpServer::~CRadadrUdpServer()
{
    deinitSocket();
    deinitMutex();
    delete []m_RecvBuf;
}

bool CRadadrUdpServer::initMutex(void)
{
    return pthread_mutex_init(&m_Mutex, NULL) == 0;
}

void CRadadrUdpServer::deinitMutex(void)
{
    if (m_bMutex)
        pthread_mutex_destroy(&m_Mutex);
    m_bMutex = false;
}

void CRadadrUdpServer::lock(void)
{
    if (m_bMutex)
        pthread_mutex_lock(&m_Mutex);
}

void CRadadrUdpServer::unlock(void)
{
    if (m_bMutex)
        pthread_mutex_unlock(&m_Mutex);
}

bool CRadadrUdpServer::initSocket(void)
{
    /* 建立udp socket */
    m_SockFd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    return m_SockFd >= 0;
}

void CRadadrUdpServer::deinitSocket(void)
{
    if (m_SockFd >= 0)
        close(m_SockFd);
    m_SockFd = -1;
}

bool CRadadrUdpServer::bindToPort(int port)
{
    struct sockaddr_in servAddr;
    /* 设置address */
    memset(&servAddr, 0, sizeof(struct sockaddr_in));
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(port);

    /* INADDR_ANY表示不管是哪个网卡接收到数据，只要目的端口是SERV_PORT，就会被该应用程序接收到 */
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    /* 绑定socket */
    if(bind(m_SockFd, (struct sockaddr *)&servAddr, sizeof(servAddr)) < 0)
        return false;
    return true;
}

bool CRadadrUdpServer::setSysUdpBuf(int size)
{
    int rst = setsockopt(m_SockFd, SOL_SOCKET, SO_RCVBUF, (const char*)&size, sizeof(int));
    return rst == 0;
}

void CRadadrUdpServer::start(int obj_id)
{
    m_self.obj = this;
    m_self.obj_id = obj_id;

    pthread_create(&m_TRecv, NULL, threadRecvLoop, (void*)(&m_self));
    pthread_create(&m_TDeal, NULL, threadDealLoop, (void*)(&m_self));
}

void CRadadrUdpServer::parseBuf(DT_BYTE *buf, int len)
{
    int i = 0;
    int iMax = 0;
    FILE *p_file = NULL;

    p_file = fopen("echo.dat", "a+");
    if(NULL == p_file)
    {
        fprintf(stderr, "open %s failed.\n", "echo.dat");
        return;
    }

    iMax = len;
    for(i=0;i<iMax;i++)
    {
        fprintf(p_file, "%02x ", buf[i]);
    }
    fprintf(p_file, "\n");
    fflush(p_file);

    fclose(p_file);
}

void* threadRecvLoop(void *argv)
{
    long all_num = 0;
    TAG_RADAR_THREAD_OBJ* to = (TAG_RADAR_THREAD_OBJ*)argv;
    CRadadrUdpServer *obj = to->obj;
    if (obj->m_SockFd < 0)
        return NULL;

    struct sockaddr_in clientAddr;
    int len = 0;

    printf("begin threadRecvLoop.\n");
    fflush(stdout);

    while(true)
    {
        int recvNum = recvfrom(obj->m_SockFd,
                obj->m_RecvBuf,
                obj->m_RecvBufSize, 
                0/* MSG_DONTWAIT*/,
                (struct sockaddr *)&clientAddr,
                (socklen_t *)&len);

        if (-1 == recvNum)
        {
            /* 出错 */
            continue;
        }
        gTotalBytes += recvNum;
    }

    return NULL;
}

void* threadDealLoop(void *argv)
{
    int rst = 0;
    double passed_seconds = 0;
    long usec = 0;
    struct timeval last;
    struct timeval now; 

    printf("begin threadDealLoop.\n");
    fflush(stdout);

    while(true)
    {
        rst = gettimeofday(&now, NULL);
        assert(0 == rst); 

        passed_seconds = difftime(now.tv_sec, last.tv_sec); 
        usec = now.tv_usec - last.tv_usec; 
        passed_seconds = 1.0 * passed_seconds + usec * 0.000001; 

        if(passed_seconds >= 1.0)
        {
            printf("total %ld BYTE \n", gTotalBytes);
            fflush(stdout);
            rst = gettimeofday(&last, NULL);
            assert(0 == rst); 
        }

        /* obj->parseBuf(obj->m_RecvBuf, recvNum); */
    }
}


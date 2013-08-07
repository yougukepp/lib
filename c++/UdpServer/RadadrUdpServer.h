#ifndef RADADRUDPSERVER_H_
#define RADADRUDPSERVER_H_

#include <assert.h>
#include <errno.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <sys/resource.h>
#include <stdio.h>
#include <malloc.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <memory.h>
#include <float.h>
#include <time.h>
#include <iostream>
#include <netdb.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <sys/file.h>
#include <pthread.h>

typedef unsigned char DT_BYTE;
class CRadadrUdpServer;

typedef struct
{
	CRadadrUdpServer*  	obj;
	int                     obj_id;
}TAG_RADAR_THREAD_OBJ;

typedef struct
{
    DT_BYTE buf[4096];
    int len;
}TAG_RADAR_UDP_PKG;

class CRadadrUdpServer
{
public:
	CRadadrUdpServer(int port);
	virtual ~CRadadrUdpServer();
public:
	void start(int obj_id);
	void parseBuf(DT_BYTE *buf, int len);

        void lock(void);
        void unlock(void);

protected:
	bool initSocket(void);
	void deinitSocket(void);
	bool bindToPort(int port);
	bool setSysUdpBuf(int size);

protected:
        bool initMutex(void);
        void deinitMutex(void);
public:
        pthread_t               m_TRecv;
        pthread_t 	        m_TDeal;

        int 		        m_SockFd;

        pthread_mutex_t         m_Mutex;
        bool		        m_bMutex;

        std::vector<TAG_RADAR_UDP_PKG> m_Buf;
private:
        TAG_RADAR_THREAD_OBJ    m_self;
};

#endif /* RADADRUDPSERVER_H_ */

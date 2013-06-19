#ifndef __QG_EGL_H__
#define __QG_EGL_H__

#include "QgInnerInterface.h"

class QgEgl
{
public:
    QgEgl(void);
    ~QgEgl(void);

    void SetDisplayFunc(QgCallBackFunc draw); 
    void BeginRender(void);

protected:
    void SwapBuffers(void);
    int GetHeight(void);
    int GetWidth(void);


private: 
    EGLDisplay egldisplay;
    EGLSurface eglsurface;
    Display *display;

    QgCallBackFunc m_draw;
};

#endif

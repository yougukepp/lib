#ifndef __GIS_EGL_H__
#define __GIS_EGL_H__

#include "GisHeader.h"

class GisEgl
{
public:
    GisEgl(void);
    ~GisEgl(void);

    void SetDisplayFunc(GisCallBackFunc draw); 
    void BeginRender(void);

protected:
    void SwapBuffers(void);
    int GetHeight(void);
    int GetWidth(void);


private: 
    EGLDisplay egldisplay;
    EGLSurface eglsurface;
    Display *display;

    GisCallBackFunc m_draw;
};

static void printFps(void);

#endif

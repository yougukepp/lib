#include "QgEgl.h"

static void printFps(void *pFrameId);

QgEgl::QgEgl(void)
{
    static const GLint s_configAttribs[] =
    {
        EGL_RENDERABLE_TYPE,    EGL_OPENGL_ES2_BIT,
        EGL_SURFACE_TYPE,       EGL_WINDOW_BIT,
        EGL_RED_SIZE,           8,
        EGL_GREEN_SIZE,         8,
        EGL_BLUE_SIZE,          8,
        EGL_ALPHA_SIZE,         0,
        EGL_SAMPLES,            0,
        EGL_DEPTH_SIZE,         8,
        EGL_NONE
    };

    GLint ContextAttribList[] = {
        EGL_CONTEXT_CLIENT_VERSION, 2,
        EGL_NONE };

    GLint               numconfigs;
    EGLConfig           eglconfig;
    EGLContext          eglcontext;

    GLint               screen;
    Window              window;
    Window              rootwindow; 

    printf("XOpenDisplay \n");
    display = XOpenDisplay(NULL);
    assert(display != NULL);   

    printf("DefaultScreen [");
    screen = DefaultScreen(display);
    printf("%d]\n", screen);

    printf("RootWindow \n");
    rootwindow = RootWindow(display,screen);

    printf("eglGetDisplay (%p)\n", (GLvoid *)display);
    egldisplay = eglGetDisplay ( display );
    assert(eglGetError() == EGL_SUCCESS);

    printf("Disp = %p \n",(GLvoid *) egldisplay);

    printf("eglInitialize \n");
    eglInitialize(egldisplay, NULL, NULL);
    assert(eglGetError() == EGL_SUCCESS);

    printf("eglBindAPI \n");
    eglBindAPI(EGL_OPENGL_ES_API);

    printf("eglChooseConfig \n");
    eglChooseConfig(egldisplay, s_configAttribs, &eglconfig, 1, &numconfigs);
    assert(eglGetError() == EGL_SUCCESS);

    assert(numconfigs == 1);

    printf("XCreateSimpleWindow \n");
    window = XCreateSimpleWindow(display, rootwindow, 0, 0,
            500, 500, 0, 0, WhitePixel (display, screen));

    XMapWindow(display, window);

    printf("eglCreateWindowSurface \n");
    eglsurface = eglCreateWindowSurface(egldisplay, eglconfig, window, NULL);
    assert(eglGetError() == EGL_SUCCESS);

    eglcontext = eglCreateContext( egldisplay, eglconfig, EGL_NO_CONTEXT, ContextAttribList );
    assert(eglGetError() == EGL_SUCCESS);
    eglMakeCurrent(egldisplay, eglsurface, eglsurface, eglcontext);
    assert(eglGetError() == EGL_SUCCESS);
}

QgEgl::~QgEgl(void)
{
    eglMakeCurrent(egldisplay, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
    assert(eglGetError() == EGL_SUCCESS);
    eglTerminate(egldisplay);
    assert(eglGetError() == EGL_SUCCESS);
    eglReleaseThread();
    XCloseDisplay(display);
}

void QgEgl::SetDisplayFunc(QgCallBackFunc draw)
{
    m_draw = draw;
} 

static void printFps(void *pFrameId)
{
    int *pFId = NULL;
    static int lastId = 0;
    int framePlayed = 0;

    pFId = (int *)pFrameId;

    framePlayed = *pFId - lastId;

    /* printf("\b\b\b\b\b\b\b\b"); */
    printf("bps:% 3d% 3d\n", framePlayed, *pFId);
    fflush(stdout);

    lastId =*pFId;

}

void QgEgl::BeginRender(void)
{
    int frameId = 0;

    frameId = 1;

    glViewport(0, 0, GetWidth(), GetHeight());
    glClear(GL_COLOR_BUFFER_BIT); 
    
#ifdef __DEBUG_QG_PRINT_FPS__
    HyTimer timer = HyTimer();
    timer.SetInterval(1000);                                    // 1 Second
    timer.SetCallBackFunc(printFps, &frameId);
    timer.Start();
#endif

    while(true)
    {
        glClear(GL_COLOR_BUFFER_BIT);

        m_draw(); 
        glFinish();
        SwapBuffers(); 

        frameId++;
        if(QG_RUNNING_FRAME_NUMS <= frameId)
        {
            break;
        }
    }

#ifdef __DEBUG_QG_PRINT_FPS__
    timer.Stop();
#endif

}

void QgEgl::SwapBuffers(void)
{
    eglSwapBuffers(egldisplay, eglsurface);
}

int QgEgl::GetWidth(void)
{
    GLint width = 0;
    eglQuerySurface(egldisplay, eglsurface, EGL_WIDTH, &width);
    return width;
}

int QgEgl::GetHeight(void)
{
    GLint height = 0;
    eglQuerySurface(egldisplay, eglsurface, EGL_HEIGHT, &height);
    return height;
}


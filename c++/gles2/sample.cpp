#include <unistd.h>
#include "GisInterface.h"


static void draw(void);

int main(int argc, char *argv[])
{
    EsInit();
    int frameId = 0;

    frameId = 1;
    while(true)
    {
        draw(); 
        glFinish();
        ESSwapBuffers();

        sleep(1);
        fprintf(stderr, "frame:%d\n", frameId++);
    }

    EsDeInit();
    return 0;
}

static void draw(void)
{
    GisLines *p_line = new GisLines();

    GisPoint p1(-0.9f, -0.9f);
    GisPoint p2(0.9f, 0.9f);
    GisPoint p3(0.9f, -0.9f);
    GisPoint p4(-0.9f, 0.9f);
    std::vector<GisPoint> points1;
    points1.push_back(p1);
    points1.push_back(p2);
    points1.push_back(p3);
    points1.push_back(p4);
    GisColor c(1.0f, 0.0f, 0.0f);

    p_line->draw(points1, c);

#if 0

    float[][] point2 = {
        {-0.9f, 0.9f},
        {0.9f, -0.9f}        	
    };
    float[] rgb2 = {0.0f, 1.0f, 0.0f};
    mLines.draw(point2, rgb2);

    float[][] points3 = {
        {0.0f, 0.9f},
        {-0.9f, 0f},
        {0.0f, -0.9f},
        {0.9f, 0f} 
    };
    float[] rgb3 = {0.0f, 0.0f, 1.0f};
    mPolygon.draw(points3, rgb3);

    float[][] points4 = {
        {-0.9f, 0.9f},
        {-0.9f, 0f},
        {0.0f, -0.9f},
        {0.9f, 0f} 
    };
    float[] rgb4 = {0.0f, 0.0f, 1.0f};
    mArc.draw(points4, rgb4);
#endif

    delete p_line;
}

#if 0


#define MAX_FRAME_NUMS          (900)
#define K                       (1024)
#define BUF_SIZE                (10*K)

#define LINE_POINT              (2)

#define POSITION_INDEX          (0)
#define POSITION_SIZE           (4)
#define POSITION_OFFSET         (0)

#define COLOR_INDEX             (1)
#define COLOR_SIZE              (4)
#define COLOR_OFFSET            (4)

#define ATTR_SIZE               (POSITION_SIZE + COLOR_SIZE)


GLfloat gVertexData[] ={
    0.0f,  1.0f,  0.0f,  1.0f,       1.0f, 0.0f, 0.0f, 0.0f,
    -1.0f, -1.0f,  0.0f,  1.0f,       0.0f, 1.0f, 0.0f, 0.0f,
    1.0f, -1.0f,  0.0f,  1.0f,       0.0f, 0.0f, 1.0f, 0.0f,
    0.0f,  0.0f,  1.0f,  1.0f,       1.0f, 1.0f, 1.0f, 0.0f

};

GLchar *gAtrriTable[] =
{
    "g_vPosition",               /* position value in vertex shader */
    "g_vColor"                   /* color value in vertex shader */
};

GLubyte t1[] = {0, 1, 2};
GLubyte t2[] = {1, 2, 3};
GLubyte t3[] = {0, 3, 1};
GLubyte t4[] = {0, 2, 3};

static void render(GLint);
int main(int argc, char *argv[])
{
    char vertexBuf[BUF_SIZE] = {0};
    char fragmentBuf[BUF_SIZE] = {0};
    int programId = 0;
    int current_frame = 0;

    EsInit();

    ReadShaderSrc("./glsl/vertex.glsl", vertexBuf, BUF_SIZE);
    /* printf("vertex shader content:\n%s", vertexBuf); */

    ReadShaderSrc("./glsl/fragment.glsl", fragmentBuf, BUF_SIZE); 
    /* printf("fragment shader content:\n%s", fragmentBuf); */

    programId = EsLoaderProgram(vertexBuf, fragmentBuf);

    EsBindAttribLocation(programId, gAtrriTable, sizeof(gAtrriTable) / sizeof(GLfloat));

    EsLinkProgram(programId);
    glUseProgram(programId);

    glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
    glEnable(GL_DEPTH_TEST);

    while (current_frame < MAX_FRAME_NUMS)
    {
        render(programId);
        current_frame++;
        ESSwapBuffers();
    }

    EsDeInit();
    return 0;
}

static void render(GLint programId)
{
    glViewport(0, 0, getWidth(), getHeight());
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    static GLfloat fAngle = 0.0f;
    GLfloat scaleMat[16] = {0};
    GLfloat roataMat[16] = {0};
    GLint scaleMatIndex = 0;
    GLint roataMatIndex = 0;

#define PI (3.1415926)
    /* 0 -> 2*3.1415926 */
    if(fAngle >= 2 * PI)
    {
        fAngle = 0;
    }
    else
    {
        fAngle += 0.01f;
    }
    printf("angle:%f\n", fAngle/2/PI*360);
#undef PI

    scaleMat[ 0] = 1.0f;
    scaleMat[ 5] = 1.0f;
    scaleMat[10] = 1.0f;
    scaleMat[15] = 1.0f;

    roataMat[ 0] = cosf(fAngle);
    roataMat[ 2] = sinf(fAngle);
    roataMat[ 5] = 1.0f;
    roataMat[ 8] = -sinf(fAngle);
    roataMat[10] = cosf(fAngle);
    roataMat[15] = 1.0f;

    scaleMatIndex = glGetUniformLocation(programId, "g_scaleMat");
    roataMatIndex = glGetUniformLocation(programId, "g_roataMat");

    glUniformMatrix4fv(scaleMatIndex, 1, 0, scaleMat);
    glUniformMatrix4fv(roataMatIndex, 1, 0, roataMat);
    
    glVertexAttribPointer(POSITION_INDEX,
            POSITION_SIZE,
            GL_FLOAT,
            GL_FALSE,
            ATTR_SIZE * sizeof(GLfloat),
            gVertexData + POSITION_OFFSET);
    glEnableVertexAttribArray(POSITION_INDEX);

    glVertexAttribPointer( COLOR_INDEX,
            COLOR_SIZE,
            GL_FLOAT,
            GL_FALSE,
            ATTR_SIZE * sizeof(GLfloat),
            gVertexData + COLOR_OFFSET);
    glEnableVertexAttribArray(COLOR_INDEX);

    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, t1);
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, t2);
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, t3);
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, t4);

    glDisableVertexAttribArray(POSITION_INDEX);
    glDisableVertexAttribArray(COLOR_INDEX);
}
#endif



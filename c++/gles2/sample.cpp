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
    GisLines *pLine = NULL;
    GisPolygon *pPolygon = NULL;
    GisRect *pRect = NULL;

    GisPoint p1(-0.9f, -0.9f);
    GisPoint p2(0.9f, 0.9f);
    GisPoint p3(0.9f, -0.9f);
    GisPoint p4(-0.9f, 0.9f);
    std::vector<GisPoint> points1;
    points1.push_back(p1);
    points1.push_back(p2);
    points1.push_back(p3);
    points1.push_back(p4);
    GisColor c1(1.0f, 0.0f, 0.0f);

    GisPoint p5(0.0f, 0.9f);
    GisPoint p6(-0.9f, 0.0f);
    GisPoint p7(0.0f, -0.9f);
    GisPoint p8(0.9f, 0.0f);
    std::vector<GisPoint> points2;
    points2.push_back(p5);
    points2.push_back(p6);
    points2.push_back(p7);
    points2.push_back(p8);
    GisColor c2(0.0f, 1.0f, 0.0f);

    GisPoint p9(-0.9f, 0.9f);
    GisPoint p10(-0.9f, -0.9f);
    GisPoint p11(0.9f, -0.9f);
    GisPoint p12(0.9f, 0.9f);
    std::vector<GisPoint> points3;
    points3.push_back(p9);
    points3.push_back(p10);
    points3.push_back(p11);
    points3.push_back(p12);
    GisColor c3(0.0f, 0.0f, 1.0f);

    pLine = new GisLines(points1);
    pPolygon = new GisPolygon(points2);
    pRect = new GisRect(points3);

    pLine->draw(c1);
    pPolygon->draw(c2);
    pRect->draw(c3);

#if 0
    pLine->draw(points1, c1);
    pPolygon->draw(points2, c2);

    float[][] points4 = {
        {-0.9f, 0.9f},
        {-0.9f, 0f},
        {0.0f, -0.9f},
        {0.9f, 0f} 
    };
    float[] rgb4 = {0.0f, 0.0f, 1.0f};
    mArc.draw(points4, rgb4);
#endif

    delete pRect;
    delete pPolygon;
    delete pLine;
}


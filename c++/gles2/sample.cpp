#include "GisInterface.h"

static void draw(void);

int main(int argc, char *argv[])
{
    GisEgl egl = GisEgl();

    egl.SetDisplayFunc(draw); 
    egl.BeginRender();

    return 0;
}

static void draw(void)
{
    GisLines *pLine = NULL;
    GisPolygon *pPolygon = NULL;
    GisRect *pRect = NULL;
    GisCircle *pCircle = NULL;
    GisArc *pArc = NULL;

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

    GisColor c3(0.0f, 0.0f, 1.0f);

    std::vector<GisPoint> points4;
    GisColor c4(1.0f, 1.0f, 0.0f);

    GisColor c5(0.0f, 1.0f, 1.0f);

    pLine = new GisLines(points1);
    pPolygon = new GisPolygon(points2);
    pRect = new GisRect(-0.9f, 0.9f, 1.8f, 1.8f);
    pCircle = new GisCircle(GisPoint(0, 0), 0.8f);
    pArc = new GisArc(GisPoint(0,0), 0.7, GIS_PI / 4, GIS_PI / 2);

    pLine->draw(c1);
    pPolygon->draw(c2);
    pRect->draw(c3);
    pCircle->draw(c4);
    pArc->draw(c5);

    delete pCircle;
    delete pRect;
    delete pPolygon;
    delete pLine;
}


#include "GisInterface.h"

static void InitShape(void);
static void DeinitShape(void);
static void draw(void);

GisLines *pLine = NULL;
GisPolygon *pPolygon = NULL;
GisRect *pRect = NULL;
GisCircle *pCircle = NULL;
GisArc *pArc = NULL;

GisCircle *pCircle1 = NULL;
GisCircle *pCircle2 = NULL;
GisCircle *pCircle3 = NULL;
GisCircle *pCircle4 = NULL;
GisCircle *pCircle5 = NULL;
GisCircle *pCircle6 = NULL;
GisCircle *pCircle7 = NULL;

int main(int argc, char *argv[])
{
    GisEgl egl = GisEgl();

    InitShape();

    egl.SetDisplayFunc(draw); 
    egl.BeginRender();

    DeinitShape();
    return 0;
}

static void draw(void)
{
    GisColor c1(1.0f, 0.0f, 0.0f);
    GisColor c2(0.0f, 1.0f, 0.0f);
    GisColor c3(0.0f, 0.0f, 1.0f);
    GisColor c4(1.0f, 1.0f, 0.0f);
    GisColor c5(0.0f, 1.0f, 1.0f);

    pLine->draw(c1);
    pPolygon->draw(c2);
    pRect->draw(c3);
    pArc->draw(c5);
    pCircle->draw(c4);
    pCircle1->draw(c4);
    pCircle2->draw(c4);
    pCircle3->draw(c4);
    pCircle4->draw(c4);
    pCircle5->draw(c4);
    pCircle6->draw(c4);
    pCircle7->draw(c4);
}

static void InitShape(void)
{
    GisPoint p1(-0.9f, -0.9f);
    GisPoint p2(0.9f, 0.9f);
    GisPoint p3(0.9f, -0.9f);
    GisPoint p4(-0.9f, 0.9f);
    std::vector<GisPoint> points1;
    points1.push_back(p1);
    points1.push_back(p2);
    points1.push_back(p3);
    points1.push_back(p4);

    GisPoint p5(0.0f, 0.9f);
    GisPoint p6(-0.9f, 0.0f);
    GisPoint p7(0.0f, -0.9f);
    GisPoint p8(0.9f, 0.0f);
    std::vector<GisPoint> points2;
    points2.push_back(p5);
    points2.push_back(p6);
    points2.push_back(p7);
    points2.push_back(p8);

    std::vector<GisPoint> points4;

    pLine = new GisLines(points1);
    pPolygon = new GisPolygon(points2);
    pRect = new GisRect(-0.9f, 0.9f, 1.8f, 1.8f);
    pCircle = new GisCircle(GisPoint(0, 0), 0.8f);
    pArc = new GisArc(GisPoint(0,0), 0.7, GIS_PI / 4, GIS_PI / 2);

    pCircle1 = new GisCircle(GisPoint(0, 0), 0.7f);
    pCircle2 = new GisCircle(GisPoint(0, 0), 0.6f);
    pCircle3 = new GisCircle(GisPoint(0, 0), 0.5f);
    pCircle4 = new GisCircle(GisPoint(0, 0), 0.4f);
    pCircle5 = new GisCircle(GisPoint(0, 0), 0.3f);
    pCircle6 = new GisCircle(GisPoint(0, 0), 0.2f);
    pCircle7 = new GisCircle(GisPoint(0, 0), 0.1f);
}

static void DeinitShape(void)
{
    delete pCircle;
    delete pRect;
    delete pPolygon;
    delete pLine;

    delete pCircle1;
    delete pCircle2;
    delete pCircle3;
    delete pCircle4;
    delete pCircle5;
    delete pCircle6;
    delete pCircle7;
}


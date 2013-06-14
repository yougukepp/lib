#include "GisInterface.h"

static void InitShape(void);
static void DeinitShape(void);
static void Draw(void);

GisLines *pLine = NULL;
GisLines *pPolygon = NULL;
GisLines *pRect = NULL;
GisLines *pCircle = NULL;
GisLines *pArc = NULL;
GisLines *pChord = NULL;
GisLines *pPie = NULL;
GisLines *pOval = NULL;

GisColor c1(1.0f, 0.0f, 0.0f);
GisColor c2(0.0f, 1.0f, 0.0f);
GisColor c3(0.0f, 0.0f, 1.0f);
GisColor c4(0.0f, 1.0f, 1.0f);
GisColor c5(1.0f, 0.0f, 1.0f);
GisColor c6(1.0f, 1.0f, 0.0f);
GisColor c7(1.0f, 1.0f, 1.0f);
GisColor c8(0.5f, 0.0f, 0.0f);

int main(int argc, char *argv[])
{
    GisEgl egl = GisEgl();

    InitShape();

    egl.SetDisplayFunc(Draw); 
    egl.BeginRender();

    DeinitShape();
    return 0;
}

static void Draw(void)
{

    pLine->Draw();
    pPolygon->Draw();
    pRect->Draw();
    pCircle->Draw();
    pArc->Draw();
    pChord->Draw();
    pPie->Draw();
    pOval->Draw();
   
        float step = 0.005;
        static float x = 1;
        x -= step;
        if(x <= -1)
        {
            x = 1;
        }
        pOval->Translate(x, 0 , 0);

        static float s = 1;
        s -= step;
        if(s < -1)
        {
            s = 1.0;
        }
        pCircle->Scale(fabs(s), fabs(s), 1);

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

    pLine = new GisLines(points1, c1);
    pPolygon = new GisPolygon(points2, c2);
    pRect = new GisRect(-0.9f, 0.9f, 1.8f, 1.8f, c3);
    pCircle = new GisCircle(GisPoint(0, 0), 0.9f, c4);
    pPie = new GisPie(GisPoint(0,0), 0.5, 3 * GIS_PI / 8, GIS_PI / 7, c7);
    pChord = new GisChord(GisPoint(0,0), 0.6, GIS_PI / 7, GIS_PI / 6, c6);
    pArc = new GisArc(GisPoint(0,0), 0.7, GIS_PI / 5, GIS_PI / 4, c5);
    pOval = new GisOval(GisPoint(0,0), 0.2, 0.6, c8);
}

static void DeinitShape(void)
{
    delete pLine;
    delete pPolygon;
    delete pRect;
    delete pCircle;
    delete pArc;
    delete pChord;
    delete pPie;
    delete pOval;
}


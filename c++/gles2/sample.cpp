#include "QgInterface.h"

static void InitShape(void);
static void DeinitShape(void);
static void Draw(void);

QgPrimitive *pPoint = NULL;
QgPrimitive *pLine = NULL;
QgPrimitive *pTriangle = NULL;

/*
QgLines *pPolygon = NULL;
QgLines *pRect = NULL;
QgLines *pCircle = NULL;
QgLines *pArc = NULL;
QgLines *pChord = NULL;
QgLines *pPie = NULL;
QgLines *pOval = NULL;
*/

/*
QgColor c4(0.0f, 1.0f, 1.0f);
QgColor c5(1.0f, 0.0f, 1.0f);
QgColor c6(1.0f, 1.0f, 0.0f);
QgColor c7(1.0f, 1.0f, 1.0f);
QgColor c8(0.5f, 0.0f, 0.0f);
*/

int main(int argc, char *argv[])
{
    QgEgl egl = QgEgl();

    InitShape();

    egl.SetDisplayFunc(Draw); 
    egl.BeginRender();

    DeinitShape();
    return 0;
}

static void Draw(void)
{
    pPoint->Draw();
    pLine->Draw();
    pTriangle->Draw();

    /*
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

        static float r = 0;
        r += 2 * GIS_PI * step;
        pPie->Rotate(r, 2);
        if(r > 2 * GIS_PI)
        {
            r = 0;
        }
        */
}

static void InitShape(void)
{ 
    QgColor c1(0.0f, 1.0f, 0.0f);
    QgColor c2(0.0f, 0.0f, 1.0f);

    //pPoint = new QgPoint(0.0f, 0.0f);

    QgPoint p1(-0.9f, -0.9f);
    QgPoint p2(0.9f, 0.9f);
    pLine = new QgLine(p1, p2, c1);

    QgPoint p3(0.0f, 0.9f);
    QgPoint p5(-0.9f, -0.9f);
    QgPoint p4(0.9f, -0.9f);
    pTriangle = new QgTriangle(p3, p4, p5, c2);

    /*
    QgPoint p1(-0.9f, -0.9f);
    QgPoint p2(0.9f, 0.9f);
    QgPoint p3(0.9f, -0.9f);
    QgPoint p4(-0.9f, 0.9f);
    std::vector<QgPoint> points1;
    points1.push_back(p1);
    points1.push_back(p2);
    points1.push_back(p3);
    points1.push_back(p4);

    QgPoint p5(0.0f, 0.9f);
    QgPoint p6(-0.9f, 0.0f);
    QgPoint p7(0.0f, -0.9f);
    QgPoint p8(0.9f, 0.0f);
    std::vector<QgPoint> points2;
    points2.push_back(p5);
    points2.push_back(p6);
    points2.push_back(p7);
    points2.push_back(p8);

    std::vector<QgPoint> points4;

    pLine = new QgLines(points1, c1);
    pPolygon = new QgPolygon(points2, c2);
    pRect = new QgRect(-0.9f, 0.9f, 1.8f, 1.8f, c3);
    pCircle = new QgCircle(QgPoint(0, 0), 0.9f, c4);
    pPie = new QgPie(QgPoint(0,0), 0.5, 3 * GIS_PI / 8, GIS_PI / 7, c7);
    pChord = new QgChord(QgPoint(0,0), 0.6, GIS_PI / 7, GIS_PI / 6, c6);
    pArc = new QgArc(QgPoint(0,0), 0.7, GIS_PI / 5, GIS_PI / 4, c5);
    pOval = new QgOval(QgPoint(0,0), 0.2, 0.6, c8);
    */
}

static void DeinitShape(void)
{
    delete pPoint;
    delete pLine;
    delete pTriangle;

    /*
    delete pLine;
    delete pPolygon;
    delete pRect;
    delete pCircle;
    delete pArc;
    delete pChord;
    delete pPie;
    delete pOval;
    */
}


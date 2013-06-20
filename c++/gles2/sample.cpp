#include "QgInterface.h"

static void InitShape(void);
static void DeinitShape(void);
static void Draw(void);

QgSpritePoints *gPtrSpritePoints = NULL;
QgLines *gPtrLines = NULL;
QgLineStrip *gPtrLineStrip = NULL;
QgTriangles *gPtrTriangles = NULL;

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
    gPtrSpritePoints->Scale(0.25,0.5,0);
    gPtrSpritePoints->Translate(-0.75, 0.5, 0.0);
    gPtrSpritePoints->Draw();

    gPtrLines->Scale(0.25,0.5,0);
    gPtrLines->Translate(-0.25, 0.5, 0.0);
    gPtrLines->Draw();

    gPtrLineStrip->Scale(0.25,0.5,0);
    gPtrLineStrip->Translate(0.25, 0.5, 0.0);
    gPtrLineStrip->Draw();

    gPtrTriangles->Scale(0.25,0.5,0);
    gPtrTriangles->Translate(0.75, 0.5, 0.0);
    gPtrTriangles->Draw();
}

static void InitShape(void)
{ 
    /* 点POINTS */
    QgPoint pSp1(0.8f, 0.0f);
    QgPoint pSp2(0.0f, 0.8f);
    QgPoint pSp3(-0.8f, 0.0f);
    QgPoint pSp4(0.0f, -0.8f);
    QgColor cSp(1.0f, 0.0f, 0.0f);
    std::vector<QgPoint> pointsSp;
    pointsSp.push_back(pSp1);
    pointsSp.push_back(pSp2);
    pointsSp.push_back(pSp3);
    pointsSp.push_back(pSp4);
    gPtrSpritePoints = new QgSpritePoints(pointsSp, cSp, 5); 

    /* 线LINES */
    QgPoint pL1(-0.9f, 0.9f);
    QgPoint pL2(-0.9f, -0.9f);
    QgPoint pL3(0.9f, -0.9f);
    QgPoint pL4(0.9f, 0.9f);
    QgColor cL(0.0f, 1.0f, 0.0f);
    std::vector<QgPoint> pointsL;
    pointsL.push_back(pL1);
    pointsL.push_back(pL2);
    pointsL.push_back(pL3);
    pointsL.push_back(pL4);
    gPtrLines = new QgLines(pointsL, cL, 5);

    /* 线LINE_STRIP */
    QgPoint pLS1(-0.9f, 0.9f);
    QgPoint pLS2(-0.9f, -0.9f);
    QgPoint pLS3(0.9f, -0.9f);
    QgPoint pLS4(0.9f, 0.9f);
    QgColor cLS(0.0f, 1.0f, 0.0f);
    std::vector<QgPoint> pointsLS;
    pointsLS.push_back(pLS1);
    pointsLS.push_back(pLS2);
    pointsLS.push_back(pLS3);
    pointsLS.push_back(pLS4);
    gPtrLineStrip = new QgLineStrip(pointsLS, cLS, 2);

    /* 三角形 */
    QgPoint pT1(-0.7f, 0.2f);
    QgPoint pT2(-0.7f, -0.7f);
    QgPoint pT3(0.2f, -0.7f);
    QgPoint pT4(0.7f, -0.2f);
    QgPoint pT5(0.7f, 0.7f);
    QgPoint pT6(-0.2f, 0.7f);
    QgColor cT(0.0f, 0.0f, 1.0f);
    std::vector<QgPoint> pointsT;
    pointsT.push_back(pT1);
    pointsT.push_back(pT2);
    pointsT.push_back(pT3);
    pointsT.push_back(pT4);
    pointsT.push_back(pT5);
    pointsT.push_back(pT6);
    gPtrTriangles = new QgTriangles(pointsT, cT);
}

static void DeinitShape(void)
{
    delete gPtrSpritePoints;
    delete gPtrLines;
    delete gPtrLineStrip;
    delete gPtrTriangles;
}


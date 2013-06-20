#include "QgInterface.h"

static void InitShape(void);
static void DeinitShape(void);
static void Draw(void);

static float gScale = 0.8f;

QgSpritePoints *gPtrSpritePoints = NULL;

QgLines *gPtrLines = NULL;
QgLineStrip *gPtrLineStrip = NULL;
QgLineLoop *gPtrLineLoop = NULL;

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

    gPtrLineLoop->Scale(0.25,0.5,0);
    gPtrLineLoop->Translate(0.75, 0.5, 0.0);
    gPtrLineLoop->Draw();

    gPtrTriangles->Scale(0.25,0.5,0);
    gPtrTriangles->Translate(0.75, -0.5, 0.0);
    gPtrTriangles->Draw();
}

static void InitShape(void)
{ 
    /* 点POINTS */
    QgPoint pSp1(-gScale, gScale);
    QgPoint pSp2(-gScale, -gScale);
    QgPoint pSp3(gScale, -gScale);
    QgPoint pSp4(gScale, gScale);
    QgColor cSp(1.0f, 0.0f, 0.0f);
    std::vector<QgPoint> pointsSp;
    pointsSp.push_back(pSp1);
    pointsSp.push_back(pSp2);
    pointsSp.push_back(pSp3);
    pointsSp.push_back(pSp4);
    gPtrSpritePoints = new QgSpritePoints(pointsSp, cSp, 5); 

    /* 线LINES */
    QgPoint pL1(-gScale, gScale);
    QgPoint pL2(-gScale, -gScale);
    QgPoint pL3(gScale, -gScale);
    QgPoint pL4(gScale, gScale);
    QgColor cL(0.0f, 1.0f, 0.0f);
    std::vector<QgPoint> pointsL;
    pointsL.push_back(pL1);
    pointsL.push_back(pL2);
    pointsL.push_back(pL3);
    pointsL.push_back(pL4);
    gPtrLines = new QgLines(pointsL, cL, 3);

    /* 线LINE_STRIP */
    QgPoint pLS1(-gScale, gScale);
    QgPoint pLS2(-gScale, -gScale);
    QgPoint pLS3(gScale, -gScale);
    QgPoint pLS4(gScale, gScale);
    QgColor cLS(0.0f, 1.0f, 0.0f);
    std::vector<QgPoint> pointsLS;
    pointsLS.push_back(pLS1);
    pointsLS.push_back(pLS2);
    pointsLS.push_back(pLS3);
    pointsLS.push_back(pLS4);
    gPtrLineStrip = new QgLineStrip(pointsLS, cLS, 2);

    /* 线LINE_LOOP */
    QgPoint pLL1(-gScale, gScale);
    QgPoint pLL2(-gScale, -gScale);
    QgPoint pLL3(gScale, -gScale);
    QgPoint pLL4(gScale, gScale);
    QgColor cLL(0.0f, 1.0f, 0.0f);
    std::vector<QgPoint> pointsLL;
    pointsLL.push_back(pLL1);
    pointsLL.push_back(pLL2);
    pointsLL.push_back(pLL3);
    pointsLL.push_back(pLL4);
    gPtrLineLoop = new QgLineLoop(pointsLL, cLL, 1);

    /* 三角形 */
    QgPoint pT1(-gScale, gScale*gScale);
    QgPoint pT2(-gScale, -gScale);
    QgPoint pT3(gScale*gScale, -gScale);
    QgPoint pT4(gScale, -gScale*gScale);
    QgPoint pT5(gScale, gScale);
    QgPoint pT6(-gScale*gScale, gScale);
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
    delete gPtrLineLoop;

    delete gPtrTriangles;
}


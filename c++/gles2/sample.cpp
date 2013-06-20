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
QgTriangleStrip *gPtrTriangleStrip = NULL;
QgTriangleFan *gPtrTriangleFan = NULL;

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
    gPtrTriangles->Translate(-0.75, -0.5, 0.0);
    gPtrTriangles->Draw();

    gPtrTriangleStrip->Scale(0.25,0.5,0);
    gPtrTriangleStrip->Translate(-0.25, -0.5, 0.0);
    gPtrTriangleStrip->Draw();

    gPtrTriangleFan->Scale(0.25,0.5,0);
    gPtrTriangleFan->Translate(0.25, -0.5, 0.0);
    gPtrTriangleFan->Draw();
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

    /* 三角形TRIANGLES */
    QgPoint pTS1(-gScale, gScale*gScale);
    QgPoint pTS2(-gScale, -gScale);
    QgPoint pTS3(gScale*gScale, -gScale);
    QgPoint pTS4(gScale, -gScale*gScale);
    QgPoint pTS5(gScale, gScale);
    QgPoint pTS6(-gScale*gScale, gScale);
    QgColor cTS(0.0f, 0.0f, 1.0f);
    std::vector<QgPoint> pointsTS;
    pointsTS.push_back(pTS1);
    pointsTS.push_back(pTS2);
    pointsTS.push_back(pTS3);
    pointsTS.push_back(pTS4);
    pointsTS.push_back(pTS5);
    pointsTS.push_back(pTS6);
    gPtrTriangles = new QgTriangles(pointsTS, cTS);

    /* 三角形TRIANGLE_STRIP */
    QgPoint pTST1(-gScale, 0);
    QgPoint pTST2(-gScale, gScale);
    QgPoint pTST3(0, 0);
    QgPoint pTST4(gScale*gScale, gScale*gScale);
    QgColor cTST(0.0f, 0.0f, 1.0f);
    std::vector<QgPoint> pointsTST;
    pointsTST.push_back(pTST1);
    pointsTST.push_back(pTST2);
    pointsTST.push_back(pTST3);
    pointsTST.push_back(pTST4);
    gPtrTriangleStrip = new QgTriangleStrip(pointsTST, cTST);

    /* 三角形TRIANGLE_FAN */
    QgPoint pTF1(0, 0);
    QgPoint pTF2(-gScale, gScale * gScale);
    QgPoint pTF3(0, gScale);
    QgPoint pTF4(gScale, gScale * gScale);
    QgColor cTF(0.0f, 0.0f, 1.0f);
    std::vector<QgPoint> pointsTF;
    pointsTF.push_back(pTF1);
    pointsTF.push_back(pTF2);
    pointsTF.push_back(pTF3);
    pointsTF.push_back(pTF4);
    gPtrTriangleFan = new QgTriangleFan(pointsTF, cTF);
}

static void DeinitShape(void)
{
    delete gPtrSpritePoints;

    delete gPtrLines;
    delete gPtrLineStrip;
    delete gPtrLineLoop;

    delete gPtrTriangles;
    delete gPtrTriangleStrip;
    delete gPtrTriangleFan;
}


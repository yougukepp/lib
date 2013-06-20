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
    static float sAngle = 0;
    sAngle += 0.05;
    gPtrSpritePoints->Scale(0.25,0.5,0);
    gPtrSpritePoints->Translate(-0.75, 0.5, 0.0);
    gPtrSpritePoints->Rotate(sAngle, 2);
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
    QgVertex pSp1(-gScale/5, gScale/5);
    QgVertex pSp2(-gScale/5, -gScale/5);
    QgVertex pSp3(gScale/5, -gScale/5);
    QgVertex pSp4(gScale/5, gScale/5);
    QgColor cSp(1.0f, 0.0f, 0.0f);
    std::vector<QgVertex> pointsSp;
    pointsSp.push_back(pSp1);
    pointsSp.push_back(pSp2);
    pointsSp.push_back(pSp3);
    pointsSp.push_back(pSp4);
    gPtrSpritePoints = new QgSpritePoints(pointsSp, cSp, 5); 

    /* 线LINES */
    QgVertex pL1(-gScale, gScale);
    QgVertex pL2(-gScale, -gScale);
    QgVertex pL3(gScale, -gScale);
    QgVertex pL4(gScale, gScale);
    QgColor cL(0.0f, 1.0f, 0.0f);
    std::vector<QgVertex> pointsL;
    pointsL.push_back(pL1);
    pointsL.push_back(pL2);
    pointsL.push_back(pL3);
    pointsL.push_back(pL4);
    gPtrLines = new QgLines(pointsL, cL, 3);

    /* 线LINE_STRIP */
    QgVertex pLS1(-gScale, gScale);
    QgVertex pLS2(-gScale, -gScale);
    QgVertex pLS3(gScale, -gScale);
    QgVertex pLS4(gScale, gScale);
    QgColor cLS(0.0f, 1.0f, 0.0f);
    std::vector<QgVertex> pointsLS;
    pointsLS.push_back(pLS1);
    pointsLS.push_back(pLS2);
    pointsLS.push_back(pLS3);
    pointsLS.push_back(pLS4);
    gPtrLineStrip = new QgLineStrip(pointsLS, cLS, 2);

    /* 线LINE_LOOP */
    QgVertex pLL1(-gScale, gScale);
    QgVertex pLL2(-gScale, -gScale);
    QgVertex pLL3(gScale, -gScale);
    QgVertex pLL4(gScale, gScale);
    QgColor cLL(0.0f, 1.0f, 0.0f);
    std::vector<QgVertex> pointsLL;
    pointsLL.push_back(pLL1);
    pointsLL.push_back(pLL2);
    pointsLL.push_back(pLL3);
    pointsLL.push_back(pLL4);
    gPtrLineLoop = new QgLineLoop(pointsLL, cLL, 1);

    /* 三角形TRIANGLES */
    QgVertex pTS1(-gScale, gScale*gScale);
    QgVertex pTS2(-gScale, -gScale);
    QgVertex pTS3(gScale*gScale, -gScale);
    QgVertex pTS4(gScale, -gScale*gScale);
    QgVertex pTS5(gScale, gScale);
    QgVertex pTS6(-gScale*gScale, gScale);
    QgColor cTS(0.0f, 0.0f, 1.0f);
    std::vector<QgVertex> pointsTS;
    pointsTS.push_back(pTS1);
    pointsTS.push_back(pTS2);
    pointsTS.push_back(pTS3);
    pointsTS.push_back(pTS4);
    pointsTS.push_back(pTS5);
    pointsTS.push_back(pTS6);
    gPtrTriangles = new QgTriangles(pointsTS, cTS);

    /* 三角形TRIANGLE_STRIP */
    QgVertex pTST1(-gScale, 0);
    QgVertex pTST2(-gScale, gScale);
    QgVertex pTST3(0, 0);
    QgVertex pTST4(gScale*gScale, gScale*gScale);
    QgColor cTST(0.0f, 0.0f, 1.0f);
    std::vector<QgVertex> pointsTST;
    pointsTST.push_back(pTST1);
    pointsTST.push_back(pTST2);
    pointsTST.push_back(pTST3);
    pointsTST.push_back(pTST4);
    gPtrTriangleStrip = new QgTriangleStrip(pointsTST, cTST);

    /* 三角形TRIANGLE_FAN */
    QgVertex pTF1(0, 0);
    QgVertex pTF2(-gScale, gScale * gScale);
    QgVertex pTF3(0, gScale);
    QgVertex pTF4(gScale, gScale * gScale);
    QgColor cTF(0.0f, 0.0f, 1.0f);
    std::vector<QgVertex> pointsTF;
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


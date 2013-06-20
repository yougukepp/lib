#include "QgInterface.h"

static void InitShape(void);
static void DeinitShape(void);
static void Draw(void);

QgSpritePoints *gPtrSpritePoint = NULL;
QgLines *gPtrLine = NULL;
QgTriangles *gPtrTriangle = NULL;

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
    gPtrSpritePoint->Draw();
    gPtrLine->Draw();
    gPtrTriangle->Draw();
}

static void InitShape(void)
{ 
    /* 点 */
    QgPoint pSp1(0.25f, 0.0f);
    QgPoint pSp2(0.0f, 0.25f);
    QgPoint pSp3(-0.25f, 0.0f);
    QgPoint pSp4(0.0f, -0.25f);
    QgColor cSp(1.0f, 0.0f, 0.0f);
    std::vector<QgPoint> pointsSp;
    pointsSp.push_back(pSp1);
    pointsSp.push_back(pSp2);
    pointsSp.push_back(pSp3);
    pointsSp.push_back(pSp4);
    gPtrSpritePoint = new QgSpritePoints(pointsSp, cSp, 5); 

    /* 线 */
    QgPoint pL1(-0.9f, 0.9f);
    QgPoint pL2(0.9f, -0.9f);
    QgPoint pL3(0.9f, 0.9f);
    QgPoint pL4(-0.9f, -0.9f);
    QgColor cL(0.0f, 1.0f, 0.0f);
    std::vector<QgPoint> pointsL;
    pointsL.push_back(pL1);
    pointsL.push_back(pL2);
    pointsL.push_back(pL3);
    pointsL.push_back(pL4);
    gPtrLine = new QgLines(pointsL, cL, 5);

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
    gPtrTriangle = new QgTriangles(pointsT, cT);
}

static void DeinitShape(void)
{
    delete gPtrSpritePoint;
    delete gPtrLine;
    delete gPtrTriangle;
}


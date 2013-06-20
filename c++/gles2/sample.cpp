#include "QgInterface.h"

static void InitShape(void);
static void DeinitShape(void);
static void Draw(void);

QgSpritePoint *gPtrSpritePoint = NULL;
QgLine *gPtrLine = NULL;
//QgTriangle *gPtrTriangle = NULL;

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
}

static void InitShape(void)
{ 
    /* 点 */
    QgPoint pSp(0.25f, 0.25f);
    /* TODO: 该店某些硬件无法绘制 */
    /* QgPoint pSp(0.5f, 0.5f); */
    QgColor cSp(1.0f, 0.0f, 0.0f);
    gPtrSpritePoint = new QgSpritePoint(pSp, cSp, 20); 

    /* 线 */
    QgPoint pL1(-0.9f, 0.9f);
    QgPoint pL2(0.9f, -0.9f);
    QgColor cL(0.0f, 1.0f, 0.0f);
    std::vector<QgPoint> pointsL;
    pointsL.push_back(pL1);
    pointsL.push_back(pL2);
    gPtrLine = new QgLine(pointsL, cL);

    /* 三角形 */
    /*
    QgPoint pT1(-0.9f, 0.9f);
    QgPoint pT2(-0.9f, -0.9f);
    QgPoint pT3(0.9f, -0.9f);
    QgColor cT(0.0f, 0.0f, 1.0f);
    std::vector<QgPoint> pointsL;
    pointsL.push_back(pT1);
    pointsL.push_back(pT2);
    pointsL.push_back(pT3);
    gPtrTriangle = new QgTriangle(pointsL, cL);
    */

}

static void DeinitShape(void)
{
    delete gPtrSpritePoint;
    delete gPtrLine;
    //delete gPtrTriangle;
}


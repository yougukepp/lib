#include "QgInterface.h"

static void InitShape(void);
static void DeinitShape(void);
static void Draw(void);

QgSpritePoint *gPtrSpritePoint = NULL;

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
}

static void InitShape(void)
{ 
    QgColor c1(1.0f, 1.0f, 1.0f);
    QgPoint p1(0.25f, 0.25f);
    /*TODO: 该店某些硬件无法绘制 */
    /* QgPoint p1(0.5f, 0.5f); */
    gPtrSpritePoint = new QgSpritePoint(p1, c1, 10); 
}

static void DeinitShape(void)
{
    delete gPtrSpritePoint;
}


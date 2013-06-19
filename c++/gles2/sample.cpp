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
    QgPoint p1(0.5f, 0.5f);
    QgColor c1(1.0f, 0.0f, 0.0f);
    gPtrSpritePoint = new QgSpritePoint(p1, c1, 10); 
}

static void DeinitShape(void)
{
    delete gPtrSpritePoint;
}


#include <conio.h>
#include <graphics.h>

int main(void)
{
    int xcenter, ycenter, radius;
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:/TC/BGI");

    xcenter = getmaxx() / 2;
    ycenter = getmaxy() / 2 + 20;
    radius = getmaxy() / 3;

    setfillstyle(SOLID_FILL, RED);
    pieslice(xcenter, ycenter, 0, 90, radius);

    setfillstyle(WIDE_DOT_FILL, GREEN);
    pieslice(xcenter, ycenter, 90, 135, radius);

    setfillstyle(INTERLEAVE_FILL, YELLOW);
    pieslice(xcenter - 10, ycenter, 135, 225, radius);

    setfillstyle(HATCH_FILL, BLUE);
    pieslice(xcenter, ycenter, 225, 360, radius);

    getch();
    closegraph();

    return 0;
}

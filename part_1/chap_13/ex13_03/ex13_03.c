#include <conio.h>
#include <graphics.h>
#include <stdlib.h>

int main(void)
{
    int color;
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:/BORLANDC/BGI");

    while (!kbhit()) {
        color = random(getmaxcolor() + 1);
        setcolor(color);
        line(random(getmaxx()), random(getmaxy()), random(getmaxx()),
             random(getmaxy()));
        circle(random(getmaxy()), random(getmaxy()), random(100));
    }

    closegraph();

    return 0;
}

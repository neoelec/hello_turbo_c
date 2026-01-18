#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int eangle;
    struct arccoordstype ai;
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:/BORLANDC/BGI");

    randomize();

    while (!kbhit()) {
        setcolor(random(getmaxcolor()) + 1);
        eangle = random(358) + 1;
        arc(random(getmaxx()), random(getmaxy()), random(eangle), eangle,
            random(100));
        getarccoords(&ai);
        line(ai.x, ai.y, ai.xstart, ai.ystart);
        line(ai.x, ai.y, ai.xend, ai.yend);
    }

    closegraph();

    return 0;
}

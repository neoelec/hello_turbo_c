#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>

#define MAXPOINT 6

int main(void)
{
    struct pointtype pt[MAXPOINT + 1];
    int i, gd = DETECT, gm;

    initgraph(&gd, &gm, "C:/BORLANDC/BGI");

    randomize();

    while (!kbhit()) {
        for (i = 0; i < MAXPOINT; i++) {
            pt[i].x = random(getmaxx());
            pt[i].y = random(getmaxy());
        }

        pt[MAXPOINT] = pt[0];

        setfillstyle(random(12), random(getmaxcolor()));
        fillpoly(MAXPOINT + 1, (void far *)pt);
    }

    closegraph();

    return 0;
}

#include <conio.h>
#include <dos.h>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "bezier.h"

int main(void)
{
    int gd = DETECT, gm, n = 0;

    initgraph(&gd, &gm, "C:/BORLANDC/BGI");
    randomize();

    while (!kbhit()) {
        setcolor(random(16));
        bezier(random(getmaxx()), random(getmaxy()), random(getmaxx()),
               random(getmaxy()), random(getmaxx()), random(getmaxy()),
               random(getmaxx()), random(getmaxy()));

        delay(200);

        n++;

        if (n >= 10) {
            cleardevice();
            n = 0;
        }
    }

    closegraph();

    return 0;
}

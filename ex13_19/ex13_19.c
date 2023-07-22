#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int i, j, x, y, color;
    struct viewporttype vp;
    int height, width;
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:/TC/BGI");

    getviewsettings(&vp);
    width = getmaxx() / 15;
    height = getmaxy() / 10;

    x = y = 0;
    color = 1;

    for (j = 0; j < 10; j++) {
        for (i = 0; i < 15; i++) {
            setfillstyle(SOLID_FILL, color++);
            bar(x, y, x + width, y + height);
            x += width + 1;
            color = 1 + (color % (getmaxcolor() - 2));
        }

        x = 0;
        y += height + 1;
    }

    randomize();

    while (!kbhit()) {
        setpalette(1 + random(getmaxcolor()), random(65));
    }

    closegraph();

    return 0;
}

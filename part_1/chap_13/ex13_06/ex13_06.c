#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int i;
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:/BORLANDC/BGI");

    randomize();

    for (i = 0; i < 50; i++) {
        setcolor(random(getmaxcolor() + 1));
        rectangle(random(getmaxx()), random(getmaxy()), random(getmaxx()),
                  random(getmaxy()));
    }

    setwritemode(XOR_PUT);
    setcolor(getmaxcolor());
    line(0, 0, getmaxx(), 0);

    for (i = 1; i <= getmaxy(); i++) {
        line(0, i - 1, getmaxx(), i - 1);
        line(0, i, getmaxx(), i);
    }

    line(0, getmaxy(), getmaxx(), getmaxy());

    getch();
    closegraph();

    return 0;
}

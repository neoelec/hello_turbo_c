#include <alloc.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>

#define ARROW_SIZE 10

void draw_arrow(int x, int y);

int main(void)
{
    int gd = DETECT, gm;
    void *arrow;
    int i, x, y, maxx;
    unsigned int size;

    initgraph(&gd, &gm, "C:/BORLANDC/BGI");

    maxx = getmaxx();
    x = 0;
    y = getmaxy() / 2;

    setcolor(getmaxcolor());
    draw_arrow(x, y);

    size = imagesize(x, y - ARROW_SIZE, x + (4 * ARROW_SIZE), y + ARROW_SIZE);
    arrow = malloc(size);

    getimage(x, y - ARROW_SIZE, x + (4 * ARROW_SIZE), y + ARROW_SIZE, arrow);
    randomize();

    for (i = 0; i < 20; i++) {
        setcolor(random(getmaxcolor()));
        rectangle(random(getmaxx()), random(getmaxy()), random(getmaxx()),
                  random(getmaxy()));
    }

    setcolor(getmaxcolor() + 1);

    while (!kbhit()) {
        putimage(x, y - ARROW_SIZE, arrow, XOR_PUT);

        x += ARROW_SIZE;

        if (x >= maxx) {
            x = 0;
        }

        putimage(x, y - ARROW_SIZE, arrow, XOR_PUT);
    }

    free(arrow);
    closegraph();

    return 0;
}

void draw_arrow(int x, int y)
{
    moveto(x, y);
    linerel(4 * ARROW_SIZE, 0);
    linerel(-2 * ARROW_SIZE, -1 * ARROW_SIZE);
    linerel(0, 2 * ARROW_SIZE);
    linerel(2 * ARROW_SIZE, -1 * ARROW_SIZE);
}

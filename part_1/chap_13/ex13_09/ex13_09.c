#include <conio.h>
#include <graphics.h>

#define N 5

int main(void)
{
    int data[N] = { 10, 3, 7, 18, 12 };
    int i, h, w, d, max;
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:/BORLANDC/BGI");

    max = 18;
    line(50, 50, 50, getmaxy() - 50);
    line(50, getmaxy() - 50, getmaxx() - 50, getmaxy() - 50);

    w = (getmaxx() - 100) / (N + 1);
    d = w / 4;

    for (i = 0; i < N; i++) {
        h = (getmaxy() - 100) * data[i] / max;
        setfillstyle(i + 2, (i + 1) % getmaxcolor());
        bar3d(50 + i * w, getmaxy() - 50 - h, 50 + (i + 1) * w - d,
              getmaxy() - 50, d, 1);
    }

    getch();
    closegraph();

    return 0;
}

#include <conio.h>
#include <graphics.h>
#include <math.h>

int main(void)
{
    int gd = DETECT, gm, n = 90, a = 100;
    float pi = 3.14159, a1, a2, inc, r, x, y, i;

    a1 = 0;
    a2 = pi * 2;
    inc = (a2 - a1) / n;

    initgraph(&gd, &gm, "C:/TC/BGI");

    for (i = a1; i < a2; i += inc) {
        r = a * (1 - cos(i));
        x = r * sin(i);
        y = r * cos(i);
        putpixel(getmaxx() / 2 + x, getmaxy() - (getmaxy() * 2 / 3 + y), WHITE);
    }

    getch();
    closegraph();

    return 0;
}

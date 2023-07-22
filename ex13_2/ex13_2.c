#include <conio.h>
#include <graphics.h>

int main(void)
{
    int i, maxx, maxy;
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:/TC/BGI");

    maxx = getmaxx();
    maxy = getmaxy();

    for (i = 0; i < maxx; i += 5) {
        putpixel(i, maxy / 5, WHITE);
    }

    line(maxx / 2, 0, maxx / 2, maxy);

    for (i = 0; i < maxx; i += 50) {
        rectangle(i, maxy * 2 / 5, i + 25, maxy * 2 / 5 + 25);
        bar(i, maxy * 3 / 5, i + 25, maxy * 3 / 5 + 25);
        circle(i, maxy * 4 / 5, 25);
    }

    getch();
    closegraph();

    return 0;
}

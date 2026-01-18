#include <conio.h>
#include <graphics.h>

int main(void)
{
    int i, j;
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:/BORLANDC/BGI");

    rectangle(0, 0, getmaxx(), getmaxy());

    for (i = 0, j = 20; i < getmaxx(); i += 100, j += 100) {
        moveto(i, j);

        linerel(100, 0);
        linerel(-100, 50);
        linerel(50, -70);
        linerel(50, 70);
        linerel(-100, -50);
    }

    getch();
    closegraph();

    return 0;
}

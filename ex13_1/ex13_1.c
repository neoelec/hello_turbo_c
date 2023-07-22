#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:/TC/BGI");

    if (graphresult() != grOk) {
        printf("graphics error !\n");
        exit(1);
    }

    line(0, 0, getmaxx(), getmaxy());
    getch();
    closegraph();

    return 0;
}

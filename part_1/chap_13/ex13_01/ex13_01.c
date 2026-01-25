#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int grdriver = DETECT, grmode;

    initgraph(&grdriver, &grmode, "C:/BORLANDC/BGI");

    if (graphresult() != grOk) {
        printf("graphics error !\n");
        exit(EXIT_FAILURE);
    }

    line(0, 0, getmaxx(), getmaxy());
    getch();
    closegraph();

    return 0;
}

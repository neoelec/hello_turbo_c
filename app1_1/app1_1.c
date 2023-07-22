#include <conio.h>
#include <graphics.h>
#include <stdio.h>

int main(void)
{
    char bitmap[] = {
        12,   0,    6,    0,    0x02, 0x00, 0x02, 0x00, 0x87,
        0x08, 0x97, 0x48, 0xFF, 0xF8, 0xFF, 0xF8, 0x97, 0x48,
    };
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:/TC/BGI");
    cleardevice();

    putimage(getmaxx() / 2, getmaxy() / 2, bitmap, COPY_PUT);

    getch();
    closegraph();

    return 0;
}

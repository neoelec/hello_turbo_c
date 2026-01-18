#include <conio.h>
#include <graphics.h>
#include <stdio.h>

#define HERCULESS 0
#define VGA_card 1
#define win(x1, y1, x2, y2) _win[Selector](x1, y1, x2, y2)

void H_win(int x1, int y1, int x2, int y2);
void V_win(int x1, int y1, int x2, int y2);

int Selector = VGA_card;

void (*_win[2])(int x1, int y1, int x2, int y2) = { H_win, V_win };

int main(void)
{
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:/BORLANDC/BGI");

    if (gd == HERCMONO) {
        Selector = HERCULESS;
    } else if (gd == VGA) {
        Selector = VGA_card;
    }

    cleardevice();
    win(100, 100, 400, 250);
    getch();
    closegraph();

    return 0;
}

void H_win(int x1, int y1, int x2, int y2)
{
    char pa[8] = { 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55 };

    setfillpattern(pa, getmaxcolor());
    bar(x1, y1, x2, y2);

    setcolor(WHITE);
    line(x1, y1, x2, y1);
    line(x1, y1, x1, y2);
    line(x2 - 10, y1 + 10, x2 - 10, y2 - 10);
    line(x1 + 10, y2 - 10, x2 - 10, y2 - 10);
    line(x1 + 10, y1 + 10, x2 - 10, y1 + 10);
    line(x1 + 10, y1 + 10, x1 + 10, y2 - 10);
    line(x1 + 11, y1 + 11, x1 + 11, y2 - 10);
    line(x2, y1, x2, y2);
    line(x2 + 1, y1 + 1, x2 + 1, y2 + 1);
    line(x1, y2, x2, y2);
    setfillpattern(pa, getmaxcolor());
    bar(x1 + 12, y1 + 12, x2 - 11, y2 - 11);
}

void V_win(int x1, int y1, int x2, int y2)
{
    setfillstyle(SOLID_FILL, 9);
    bar(x1, y1, x2, y2);

    setcolor(11);
    line(x1, y1, x2, y1);
    line(x1, y1, x1, y2);
    line(x2 - 10, y1 + 10, x2 - 10, y2 - 10);
    line(x1 + 10, y2 - 10, x2 - 10, y2 - 10);
    setcolor(1);
    line(x1 + 10, y1 + 10, x2 - 10, y1 + 10);
    line(x1 + 10, y1 + 10, x1 + 10, y2 - 10);
    line(x1 + 11, y1 + 11, x1 + 11, y2 - 10);
    line(x2, y1, x2, y2);
    line(x2 + 1, y1 + 1, x2 + 1, y2 + 1);
    line(x1, y2, x2, y2);
    setfillstyle(SOLID_FILL, 3);
    bar(x1 + 12, y1 + 12, x2 - 11, y2 - 11);
}

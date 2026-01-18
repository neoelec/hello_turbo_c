#include <conio.h>
#include <graphics.h>

int main(void)
{
    int gd = DETECT, gm;
    unsigned char i;
    char ch[2] = "\0\0";

    initgraph(&gd, &gm, "C:/BORLANDC/BGI");
    rectangle(0, 0, getmaxx(), getmaxy());
    outtextxy(150, 100, "Hello, Turbo C 2.0");
    outtextxy(150, 120, "Graphic mode Character Output..");
    moveto(150, 200);

    for (i = 0; i < 255; i++) {
        ch[0] = i;
        outtext(ch);

        if (((i + 1) % 32) == 0) {
            moverel(-256, 16);
        }
    }

    getch();
    closegraph();

    return 0;
}

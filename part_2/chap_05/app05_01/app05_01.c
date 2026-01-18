#include <bios.h>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define printbyte(byte) biosprint(0, (byte), 0)

void printgrscr(void)
{
    int i, j, k;
    unsigned char byte1, byte2, byte3;

    printbyte(27);
    printbyte('@');

    for (j = 0; j < getmaxy() + 1; j += 24) {
        printbyte(27);
        printbyte('*');
        printbyte(39);
        printbyte((getmaxx() + 1) % 256);
        printbyte((getmaxx() + 1) / 256);

        for (i = 0; i < getmaxx() + 1; i++) {
            byte1 = byte2 = byte3 = 0;

            for (k = 0; k < 8; k++) {
                byte1 <<= 1;
                byte2 <<= 1;
                byte3 <<= 1;
                byte1 |= getpixel(i, j + k) && 1;
                byte2 |= getpixel(i, j + 8 + k) && 1;
                byte3 |= getpixel(i, j + 16 + k) && 1;
            }

            printbyte(byte1);
            printbyte(byte2);
            printbyte(byte3);
        }

        printbyte(27);
        printbyte(60);

        printbyte(27);
        printbyte('J');
        printbyte(24);
        printbyte(13);
    }
}

void drawscr(void)
{
    int i, sx, sy;
    char ch[2];

    sx = getmaxx();
    sy = getmaxy();

    rectangle(0, 0, sx, sy);

    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);
    outtextxy(100, 30, "Screen to Printer Program Test");
    settextstyle(SMALL_FONT, HORIZ_DIR, 10);
    moveto(80, 90);

    for (i = 0; i < 128; i++) {
        sprintf(ch, "%c", i);
        outtext(ch);

        if ((i + 1) % 32 == 0) {
            moverel(-256, 16);
        }
    }

    randomize();

    for (i = 0; i < 100; i++) {
        line(80 + random(256), 170 + random(sy - 190), 80 + random(256),
             170 + random(sy - 190));
    }

    for (i = 0; i < 10; i++) {
        rectangle(380 + random(sx - 420), 90 + random(100),
                  380 + random(sx - 420), 90 + random(100));
    }

    for (i = 0; i < 60; i++) {
        setviewport(380, 210, sx - 80, sy - 20, 1);
        circle(random(sx - 80 - 380), random(sy - 20 - 210), random(20));
    }

    setviewport(0, 0, sx, sy, 1);
}

int main(void)
{
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:/BORLANDC/BGI");

    drawscr();
    printgrscr();
    closegraph();

    return 0;
}

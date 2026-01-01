#include <conio.h>
#include <dos.h>
#include <graphics.h>
#include <stdio.h>

#ifndef TRUE
#define FALSE 0
#define TRUE !FALSE
#endif
#define RETURN 0x000d
#define BS 0x0008
#define ESC 0x001b
#define INS 0x5200
#define DEL 0x5300
#define UP 0x4800
#define DOWN 0x5000
#define RIGHT 0x4d00
#define LEFT 0x4b00
#define F1 0x3b00
#define F2 0x3c00
#define HOME 0x4700
#define END 0x4f00
#define SPACE 0x0020

void shot(int ufo_x, int ufo_y, int gd);

int main(void)
{
    char green[] = {
        12,   0,    6,    0,    0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x87, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x97, 0x48, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xFF, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xFF, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x97, 0x48, 0x00, 0x00,
    };
    char white[] = {
        12,   0,    6,    0,    0x02, 0x00, 0x02, 0x00, 0x87,
        0x08, 0x97, 0x48, 0xFF, 0xF8, 0xFF, 0xF8, 0x97, 0x48,
    };
    char *bitmap;
    int ch, old_x, old_y, x, y;
    int loop = TRUE;
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:/TC/BGI");
    cleardevice();

    if (gd == VGA) {
        bitmap = green;
    } else {
        bitmap = white;
    }

    old_x = x = getmaxx() / 2;
    old_y = y = getmaxy() / 2;
    putimage(x, y, bitmap, XOR_PUT);

    while (loop) {
        if (kbhit()) {
            old_x = x;
            old_y = y;

            if ((ch = getch()) == 0) {
                ch |= getch() << 8;
            }

            switch (ch) {
            case ESC:
            case RETURN:
            case F1:
            case F2:
                loop = FALSE;
                break;

            case UP:
                y = (y <= 0) ? getmaxy() : y - 5;
                break;

            case DOWN:
                y = (y >= getmaxy()) ? 0 : y + 5;
                break;

            case LEFT:
                x = (x <= 0) ? getmaxx() : x - 5;
                break;

            case RIGHT:
                x = (x >= getmaxx()) ? 0 : x + 5;
                break;

            case SPACE:
                shot(x, y, gd);
                break;
            }

            putimage(x, y, bitmap, XOR_PUT);
            putimage(old_x, old_y, bitmap, XOR_PUT);
        }
    }

    closegraph();

    return 0;
}

void shot(int ufo_x, int ufo_y, int gd)
{
    int i, sh_y, sh_x;

    sh_x = ufo_x + 6;
    setcolor(YELLOW);
    line(sh_x, ufo_y - 1, sh_x, ufo_y - 10);

    for (i = ufo_y - 1; 10; i -= 10) {
        setcolor(YELLOW);
        line(sh_x, i - 10, sh_x, i - 20);
        delay(30);
        setcolor(BLACK);
        line(sh_x, i, sh_x, i - 10);
    }
}

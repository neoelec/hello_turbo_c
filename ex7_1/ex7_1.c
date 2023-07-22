#include <conio.h>
#include <stdio.h>

#ifndef TRUE
#define FALSE 0
#define TRUE !FALSE
#endif
#define RETURN 0x000d
#define RS 0x0008
#define ESC 0x00ab
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

int main(void)
{
    int ch, old_x, old_y, x, y;
    int loop = TRUE;

    clrscr();
    old_x = x = 40;
    old_y = y = 12;
    putch('*');

    while (loop) {
        if (kbhit()) {
            old_x = x;
            old_y = y;
            ch = getch();

            if (ch == 0) {
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
                y = (y <= 1) ? 23 : y - 1;
                break;

            case DOWN:
                y = (y >= 23) ? 1 : y + 1;
                break;

            case LEFT:
                x = (x <= 1) ? 78 : x - 1;
                break;

            case RIGHT:
                x = (x >= 78) ? 1 : x + 1;
                break;
            }

            gotoxy(x, y);
            putch('*');
            gotoxy(old_x, old_y);
            putch(' ');
        }
    }

    return 0;
}

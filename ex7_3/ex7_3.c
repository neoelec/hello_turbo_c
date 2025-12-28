#include <conio.h>
#include <stdio.h>

#include "keycode.h"

#ifndef TRUE
#define FALSE 0
#define TRUE !FALSE
#endif

int main(void)
{
    int ch, old_x, old_y, x, y;
    int loop = TRUE;

    clrscr();
    old_x = x = 40;
    old_y = y = 12;
    gotoxy(x, y);
    putch('*');

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

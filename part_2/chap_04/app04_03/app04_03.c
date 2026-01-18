#include <conio.h>
#include <dos.h>
#include <stdio.h>

void stick(int *x, int *y);
int strig(void);

int main(void)
{
    int x, y, but;

    while (!kbhit()) {
        stick(&x, &y);
        but = strig();
        printf("Buttont 1 : %d  Button 2 : %d     X : %3d   Y : %3d\n",
               but & 0x20 & 1, but & 0x10 && 1, x, y);
    }

    return 0;
}

void stick(int *x, int *y)
{
    static union REGS r;

    r.h.ah = 0x84;
    r.x.dx = 1;
    int86(0x15, &r, &r);
    *x = r.x.ax;
    *y = r.x.bx;
}

int strig(void)
{
    static union REGS r;

    r.h.ah = 0x84;
    r.x.dx = 0;
    int86(0x15, &r, &r);

    return (int)r.h.al;
}

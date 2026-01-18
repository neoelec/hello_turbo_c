#include <conio.h>
#include <dos.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int main(void)
{
    union REGS reg;
    int threebut = FALSE;

    clrscr();

    reg.x.ax = 0;
    int86(0x33, &reg, &reg);

    if (reg.x.ax == 0) {
        printf("Mouse driver not found !\n");
        exit(-1);
    }

    if (reg.x.bx == 3) {
        threebut = TRUE;
    }

    reg.x.ax = 1;
    int86(0x33, &reg, &reg);

    do {
        reg.x.ax = 3;
        int86(0x33, &reg, &reg);

        gotoxy(1, 1);
        printf("  X : %4d   Y : %d\n", reg.x.cx / 8 + 1, reg.x.dx / 8 + 1);
        printf("  Left Button   %3s\n  Right Button  %3s",
               reg.x.bx & 1 ? "ON" : "OFF", reg.x.bx & 2 ? "ON" : "OFF");

        if (threebut) {
            printf("\n  Middle Button %3s", reg.x.bx & 4 ? "ON" : "OFF");
        }
    } while (!(reg.x.bx & 1 && reg.x.bx & 2));

    reg.x.ax = 2;
    int86(0x33, &reg, &reg);

    clrscr();

    return 0;
}

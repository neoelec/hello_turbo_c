#include <conio.h>
#include <stdio.h>

#define BOX_X 25
#define BOX_Y 8

void put_box(void)
{
    int i;

    gotoxy(BOX_X, BOX_Y);
    puts("+-------------------------+");
    puts("|                         |");

    for (i = 1; i < 5; i++) {
        gotoxy(BOX_X, BOX_Y + i);
        puts("|                         |");
    }

    gotoxy(BOX_X, BOX_Y + i);
    puts("+-------------------------+");
}

#undef BOX_X
#undef BOX_Y

int main(void)
{
    clrscr();
    put_box();
    getch();

    return 0;
}

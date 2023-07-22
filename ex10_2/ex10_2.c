#include <conio.h>
#include <stdio.h>

int main(void)
{
    unsigned key;

    printf("Any key for ASCII code or ESC will stop\n");

    do {
        key = getch();

        if (key == 0) {
            key = getch() << 8;
        }

        printf("Decimal :  H %3d   L %d     Hexa : %4x\n", key >> 8, key & 0xff,
               key);
    } while (key != 27);

    return 0;
}

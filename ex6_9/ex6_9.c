#include <stdio.h>

#define DISKS 3

void move(int, int, int, int);

void move(int n, int a, int b, int c)
{
    if (n > 0) {
        move(n - 1, a, c, b);
        printf("Move a disk from %d to %d\n", a, b);
        move(n - 1, c, b, a);
    }
}

int main(void)
{
    move(DISKS, 1, 3, 2);

    return 0;
}

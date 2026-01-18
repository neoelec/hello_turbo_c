#include <stdio.h>

union ch_int {
    char ch;
    int in;
} a;

int main(void)
{
    a.in = 0xBC37;
    printf("  ch = %hhX   in = %X\n", a.ch, a.in);

    return 0;
}

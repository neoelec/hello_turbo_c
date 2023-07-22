#include <stdio.h>

union char_int {
    char ch;
    int in;
} a;

int main(void)
{
    a.in = 0xBC37;
    printf("  ch = %hhX   in = %X", a.ch, a.in);

    return 0;
}

#include <stdio.h>

union ch_int {
    char ch;
    int in;
} a;

int main(void)
{
    a.in = 0xBC37;
    printf("  ch =  %X  in = %X\n", a.ch, a.in);

    return 0;
}

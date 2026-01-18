#include <stdio.h>

int main(void)
{
    int a, b, c, d;

    d = (a = 5, b = 3, c = 4);
    printf("%d %d %d %d\n", a, b, c, d);

    return 0;
}

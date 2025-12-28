#include <stdio.h>

int main(void)
{
    int i = 0, s = 0;

    while (i <= 10) {
        i = i + 1;
        s = s + i;
    }

    printf("Total sum from 1 to 10 is %d\n", s);

    return 0;
}

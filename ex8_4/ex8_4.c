#include <stdio.h>

int main(void)
{
    int *pi, a[3] = { 10, 20, 30 };

    pi = a;
    printf(" *pi     = %d\n", *pi);

    pi = pi + 1;
    printf(" *(pi+1) = %d\n", *pi);

    return 0;
}

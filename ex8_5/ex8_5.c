#include <stdio.h>

int main(void)
{
    int *pa, *pb, x[2] = { 5, 10 };

    pa = &x[0];
    pb = &x[1];
    printf(" pb - pa = %d\n", pb - pa);
    printf(" pa - pb = %d]n", pa - pb);

    return 0;
}

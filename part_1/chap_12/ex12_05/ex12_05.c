#include <errno.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    sqrt(-1);
    printf("errno is %d\n\n", errno);
    printf("exp( 1000 ) is %lf\n", exp(1000));
    printf("errno is %d\n", errno);

    return 0;
}

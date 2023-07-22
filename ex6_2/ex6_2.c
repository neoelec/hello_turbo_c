#include <stdio.h>

long factorial(int n)
{
    int i;
    long product = 1;

    for (i = 2; i <= n; i++) {
        product *= i;
    }

    return product;
}

int main(void)
{
    int num;
    long fact;

    for (num = 1; num <= 10; num++) {
        fact = factorial(num);
        printf("%2d! = %8ld\n", num, fact);
    }

    return 0;
}

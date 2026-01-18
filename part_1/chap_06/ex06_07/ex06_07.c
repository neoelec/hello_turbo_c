#include <stdio.h>

long factorial(int);

long factorial(int n)
{
    if (n <= 1) {
        return 1;
    } else {
        return (n * factorial(n - 1));
    }
}

int main(void)
{
    int num;

    for (num = 1; num <= 10; num++) {
        printf("%2d! = %8ld\n", num, factorial(num));
    }

    return 0;
}

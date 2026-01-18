#include <stdio.h>

void print_head(void);
int prime(int n);

int main(void)
{
    int i, n;

    n = 1000;
    print_head();

    for (i = 2; i <= n; i++) {
        if (prime(i)) {
            printf("%3d ", i);
        }
    }

    return 0;
}

void print_head(void)
{
    printf("==================================================");
    printf("============================\n");
    printf("              Prime Number from 1 to 1000\n");
    printf("==================================================");
    printf("============================\n");
}

int prime(int n)
{
    int i;

    if (n % 2 == 0) {
        return (n == 2);
    }

    if (n % 3 == 0) {
        return (n == 3);
    }

    if (n % 5 == 0) {
        return (n == 5);
    }

    for (i = 7; i * i <= n; i += 2) {
        if (n % i == 0) {
            return 1;
        }
    }

    return 0;
}

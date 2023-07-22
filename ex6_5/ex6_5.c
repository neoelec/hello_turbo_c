#include <stdio.h>

int i = 1;

void print_i(void);

void print_i(void)
{
    printf("In function print_i(),i = %d\n", i);
}

int main(void)
{
    int i = 2;

    printf("%d\n", i);
    {
        int i = 3;
        printf("%d\n", i);
    }
    i++;
    printf("%d\n", i);
    print_i();

    return 0;
}

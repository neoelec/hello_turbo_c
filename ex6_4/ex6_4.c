#include <stdio.h>

void swap1(int a, int b);
void swap2(int *a, int *b);

void swap1(int a, int b)
{
    int temp;

    temp = a;
    a = b;
    b = temp;
}

void swap2(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    int a = 3, b = 5;

    printf("Initial value a = %d, b = %d\n", a, b);
    swap1(a, b);
    printf("After call swap1(a, b) : a = %d, b = %d\n", a, b);
    swap2(&a, &b);
    printf("After call swap2(&a, &b) : a = %d, b = %d\n", a, b);

    return 0;
}

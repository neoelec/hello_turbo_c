#include <stdio.h>

int func1(int val);

int main(void)
{
    int (*fptr)(int i);
    int i;

    i = 123;
    fptr = func1;
    i = (*fptr)(i);
    printf(" i = %d\n", i);

    return 0;
}

int func1(int val)
{
    printf(" val is %d\n", val);

    return (999);
}

#include <stdio.h>

void a(void)
{
    printf("Now in function a()\n");
}

int sum(int a, int b)
{
    int i, s = 0;

    printf("Now in function b()\n");

    for (i = a; i <= b; i++) {
        s = s + i;
    }

    return s;
}

int main(void)
{
    int s;

    a();
    sum(10, 20);
    s = sum(20, 60);
    printf("sum from 20 to 60 = %d\n", s);
    printf("sum from 10 to 100 = %d\n", sum(10, 100));

    return 0;
}

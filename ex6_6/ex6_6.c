#include <stdio.h>

void test(void);

void test(void)
{
    static int s_count = 0;
    int a_count = 0;

    s_count++;
    a_count++;
    printf("static count = %d\tauto count = %d\n", s_count, a_count);
}

int main(void)
{
    int i;

    for (i = 0; i < 10; i++) {
        test();
    }

    return 0;
}

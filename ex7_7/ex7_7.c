#include <stdio.h>

enum su { zero, one, two, three, four, five, six, seven, eight, nine, ten };

void test(void);

int main(void)
{
    enum su a;

    a = two + six;
    printf(" Two + Six = %d\n", a);
    test();

    return 0;
}

void test(void)
{
    enum su b;

    b = one + three;
    printf(" One + Three = %d\n", b);
}

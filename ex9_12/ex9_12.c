#include <stdio.h>

struct da {
    int x, y;
};

int total(struct da tot);

int main(void)
{
    struct da val = { 10, 30 };
    int sum = 0;

    sum = total(val);
    printf(" Sum = %d\n", sum);

    return 0;
}

int total(struct da tot)
{
    return (tot.x + tot.y);
}

#include <stdio.h>

#define MAX 10

int max_item_a(int item[]);
int max_item_b(int *item);

int main(void)
{
    int a[MAX] = { 23, 75, 12, 50, 328, 432, 58, 68, 33, 30 };
    int i;

    for (i = 0; i < MAX; i++) {
        printf(" %d    ", a[i]);
    }

    printf("\n");
    printf(" Maximum with max_item_a() = %d\n", max_item_a(a));
    printf(" Maximum with max_item_b() = %d\n", max_item_b(a));

    return 0;
}

int max_item_a(int item[])
{
    int i, max = 0;

    for (i = 0; i < MAX; i++) {
        if (max < item[i]) {
            max = item[i];
        }
    }

    return max;
}

int max_item_b(int *item)
{
    int i, max = 0;

    for (i = 0; i < MAX; i++) {
        if (max < *(item + i)) {
            max = *(item + i);
        }
    }

    return max;
}

#include <stdio.h>
#include <stdlib.h>

#define NELEMS(arr) (sizeof(arr) / sizeof(arr[0]))

int numarray[] = { 123, 145, 512, 627, 800, 933 };

int numeric(const void *p1, const void *p2)
{
    return (*(const int *)p1 - *(const int *)p2);
}

int lookup(int key)
{
    int *itemptr;

    itemptr = bsearch(&key, numarray, NELEMS(numarray), sizeof(int), numeric);

    return itemptr != NULL;
}

int main(void)
{
    if (lookup(512)) {
        printf("512 is in the table.\n");
    } else {
        printf("512 isn't in the table.\n");
    }

    return 0;
}

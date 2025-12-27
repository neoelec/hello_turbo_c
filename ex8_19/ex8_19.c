#include <stdio.h>
#include <stdlib.h>

int func1(int *ptr1, int *ptr2);

int main(void)
{
    int table[] = { 11, 22, 33, 44, 55, 66, 77, 88, 99 };
    char buff[20], *ptr;
    int key, n, w;

    w = sizeof(table[0]);
    n = sizeof(table) / w;
    printf(" Enter a value: ");

    while ((key = atoi(gets(buff))) != 0) {
        ptr = bsearch(&key, table, n, w, func1);

        if (ptr != NULL) {
            printf(" Mathch on %d and %d\n\n", key, *ptr);
        } else {
            printf(" No match found in list for %d\n\n", key);
        }

        printf(" Enter a value: ");
    }

    printf(" Process ending....!! \n");

    return 0;
}

int func1(int *ptr1, int *ptr2)
{
    return (*ptr1 - *ptr2);
}

#include <stdio.h>

void array_cpy(const void *scr, void *des, int n);

int main(void)
{
    char scr[6] = { 'A', '\0', 'B', '\0', 'C', '\0' };
    int des[4], i;

    for (i = 0; i < 6; i++) {
        printf(" Character array scr[%d] = %d\n", i, scr[i]);
    }

    printf("\n");

    array_cpy(scr, des, 6);

    for (i = 0; i < 3; i++) {
        printf(" Integer array des[%d] = %d\n", i, des[i]);
    }

    return 0;
}

void array_cpy(const void *src, void *des, int n)
{
    int i;

    for (i = 0; i < n; i++) {
        *((char *)des + i) = *((char *)src + i);
    }
}

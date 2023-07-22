/* Kawi,Bawi,Bo output program */
#include <stdio.h>

int main(void)
{
    int x, kawi = 0, bawi = 0, bo = 0;

    printf("Enter number :");
    scanf("%d", &x);

    while (x >= 0 && x <= 2) {
        if (x == 0) {
            printf("< Kawi >\n");
            kawi++;
        } else if (x == 1) {
            printf("< Bawi >\n");
            bawi++;
        } else {
            printf("< Bo >\n");
            bo++;
        }

        printf("Enter number :");
        scanf("%d", &x);
    }

    printf("Kawi :%d, Bawi %d, Bo %d\n", kawi, bawi, bo);

    return 0;
}

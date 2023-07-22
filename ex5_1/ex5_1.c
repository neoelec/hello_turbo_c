#include <stdio.h>

int main(void)
{
    int jum;

    do {
        printf("Input Jumsoo (0 for stop) : ");
        scanf("%d", &jum);
        printf(" Jumsoo : %d   Hakjum : ", jum);

        if (jum >= 96) {
            printf("A+\n");
        } else if ((jum >= 90) && (jum <= 94)) {
            printf("A0\n");
        } else if ((jum >= 85) && (jum <= 89)) {
            printf("B+\n");
        } else if ((jum >= 80) && (jum <= 84)) {
            printf("B0\n");
        } else if ((jum >= 75) && (jum <= 79)) {
            printf("C+\n");
        } else if ((jum >= 70) && (jum <= 74)) {
            printf("C0\n");
        } else if ((jum >= 65) && (jum <= 69)) {
            printf("D+\n");
        } else if ((jum >= 60) && (jum <= 64)) {
            printf("D0\n");
        } else {
            printf("F\n");
        }
    } while (jum);

    return 0;
}

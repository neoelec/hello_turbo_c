#include <stdio.h>

int main(void)
{
    int height, base;
    float extent;

    base = 5;
    printf(" Enter the length of the base:");
    scanf("%d", &height);

    if (height <= 0) {
        printf("The height is wrong.");
    } else {
        extent = 0.5 * base * height;
        printf(" The extent of a triangle is %8.2f ", extent);
    }

    return 0;
}

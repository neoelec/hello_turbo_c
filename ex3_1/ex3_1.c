#include <stdio.h>

int main(void)
{
    int boxes, kilogram;
    int total;

    kilogram = 30;
    boxes = 1500;

    total = boxes * kilogram;
    printf("There are %d kilograms in 1500 boxes of apple.\n", total);

    return 0;
}

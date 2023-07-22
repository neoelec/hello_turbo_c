#include <stdio.h>

#define MAXDATA 10

int main(void)
{
    int data[] = { 78, 55, 99, 75, 84, 19, 67, 98, 87, 100 };
    int i;
    long sum = 0;
    float ave;

    for (i = 0; i < MAXDATA; i++) {
        sum += data[i];
    }

    ave = (float)sum / MAXDATA;

    printf(" TOTAL = %ld   AVERAGE = %6.2\n", sum, ave);

    return 0;
}

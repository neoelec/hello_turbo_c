#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 10

void print_data(int item[], int count);
void bubble(int item[], int count);

int main(void)
{
    int data[MAX_NUM], a;

    randomize();

    for (a = 0; a < MAX_NUM; a++) {
        data[a] = random(MAX_NUM) + 1;
    }

    print_data(data, MAX_NUM);
    bubble(data, MAX_NUM);
    print_data(data, MAX_NUM);

    return 0;
}

void print_data(int item[], int count)
{
    register int b;

    for (b = 0; b < count; b++) {
        printf("%3d", item[b]);
    }

    printf("\n");
}

void bubble(int item[], int count)
{
    register int i, j, temp;

    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (item[j] > item[j + 1]) {
                temp = item[j];
                item[j] = item[j + 1];
                item[j + 1] = temp;
            }
        }
    }
}

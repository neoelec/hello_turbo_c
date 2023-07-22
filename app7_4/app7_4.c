#include <stdio.h>
#include <stdlib.h>

int seq_search(int item[], int count, int key);
int b_search(int item[], int count, int key);

int main(void)
{
    int num;
    int data[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    char s[2];

    printf("\nEnter the number: ");

    while (*gets(s) != '\0') {
        if (seq_search(data, 10, num = atoi(s)) != -1) {
            puts("Found !");
            printf("The location is [%2d].\n", b_search(data, 10, num));
        } else {
            puts("Not found !");
        }

        printf("\nEnter the number: ");
    }

    puts("End..");

    return 0;
}

int seq_search(int item[], int count, int key)
{
    register int i;

    for (i = 0; i < count; i++) {
        if (key == item[i]) {
            return i;
        }
    }

    return -1;
}

int b_search(int item[], int count, int key)
{
    int low = 0, high = count - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (key < item[mid]) {
            high = mid - 1;
        } else if (key > item[mid]) {
            low = mid + 1;
        } else {
            return mid;
        }
    }

    return -1;
}

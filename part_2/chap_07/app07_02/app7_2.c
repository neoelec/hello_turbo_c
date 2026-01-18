#include <dos.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 2000

void bubble(int item[], int count);
void select(int item[], int count);
void insert(int item[], int count);
void shell(int item[], int count);
void insertsort(int start, int inc, int item[], int count);
void quick(int item[], int count);
void qs(int item[], int left, int right);
void calc(char *s, int selection, int data[]);

int main(void)
{
    register int a;
    int data[MAX];

    randomize();

    for (a = 0; a < MAX; a++) {
        data[a] = random(MAX);
    }

    calc("Bubble", 0, data);
    calc("Select", 1, data);
    calc("Insert", 2, data);
    calc("Shell", 3, data);
    calc("Quick", 4, data);

    return 0;
}

void calc(char *s, int selection, int data[])
{
    register int c;
    clock_t start, end, seconds, time;
    int copy[MAX];

    start = clock();
    c = MAX;

    while (c-- > 0) {
        copy[c] = data[c];
    }

    switch (selection) {
    case 0:
        bubble(copy, MAX);
        break;

    case 1:
        select(copy, MAX);
        break;

    case 2:
        insert(copy, MAX);
        break;

    case 3:
        shell(copy, MAX);
        break;

    case 4:
        quick(copy, MAX);
        break;
    }

    end = clock();
    time = end - start;
    seconds = time / CLK_TCK;
    printf(" %s sort took %ld processor time. (%ld seconds)\n", s, time,
           seconds);
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

void select_legacy(int item[], int count)
{
    register int i, j, temp;

    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            if (item[i] > item[j]) {
                temp = item[j];
                item[j] = item[i];
                item[i] = temp;
            }
        }
    }
}

void select(int item[], int count)
{
    register int i, j, temp, k;

    for (i = 0; i < count - 1; i++) {
        k = i;
        temp = item[i];

        for (j = i + 1; j < count; j++) {
            if (temp > item[j]) {
                k = j;
                temp = item[j];
            }
        }

        item[k] = item[i];
        item[i] = temp;
    }
}

void insert(int item[], int count)
{
    register int i, j, temp;

    for (i = 1; i < count; i++) {
        temp = item[i];

        j = i - 1;

        while (j >= 0 && item[j] > temp) {
            item[j + 1] = item[j];
            j--;
        }

        item[j + 1] = temp;
    }
}

void shell(int item[], int count)
{
    register int begin, inc = count;

    do {
        inc = inc / 3 + 1;

        for (begin = 0; begin < inc; begin++) {
            insertsort(begin, inc, item, count);
        }
    } while (inc > 1);
}

void insertsort(int start, int inc, int item[], int count)
{
    register int i, j, temp;

    for (i = start; i < count; i += inc) {
        temp = item[i];

        j = i - inc;

        while (j >= 0 && item[j] > temp) {
            item[j + inc] = item[j];
            j -= inc;
        }

        item[j + inc] = temp;
    }
}

void quick(int item[], int count)
{
    qs(item, 0, count - 1);
}

void qs(int item[], int left, int right)
{
    register int i = left, j = right + 1, pivot, temp;

    pivot = item[left];

    if (left < right) {
        do {
            do {
                i++;
            } while (item[i] < pivot);

            do {
                j--;
            } while (item[j] > pivot);

            if (i < j) {
                temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        } while (i < j);

        item[left] = item[j];
        item[j] = pivot;

        qs(item, left, j - 1);
        qs(item, j + 1, right);
    }
}

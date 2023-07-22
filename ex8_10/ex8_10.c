#include <stdio.h>
#include <string.h>

#define MAX 7

void sort_name(char *ptr[]);
void list(const char *ptr[]);

int main(void)
{
    char *name[MAX] = {
        "Howard Ashman",     "Alan Menken",        "Brian W. Kernighan",
        "Dennis M. Ritchie", "Lawrence H. Miller", "Al Kelly",
        "Ira Pohl",
    };
    char *n_ptr[MAX];
    int i;

    for (i = 0; i < MAX; i++) {
        n_ptr[i] = name[i];
    }

    printf(" Unsorted list ----------------\n");
    list(n_ptr);
    sort_name(n_ptr);
    printf("\n");
    printf(" Sorted list ------------------\n");
    list(n_ptr);

    return 0;
}

void sort_name(char *ptr[])
{
    int i, j;
    char *tem;

    for (i = 0; i < MAX; i++) {
        for (j = i; j < MAX; j++) {
            if (strcmp(ptr[i], ptr[j]) > 0) {
                tem = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = tem;
            }
        }
    }
}

void list(const char *ptr[])
{
    int i;

    for (i = 0; i < MAX; i++) {
        printf(" %s\n", ptr[i]);
    }
}

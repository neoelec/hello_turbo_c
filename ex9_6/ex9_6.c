#include <stdio.h>

typedef struct {
    char name[30];
    int kor;
    int eng;
    int math;
    int total;
    float ave;
} MAN;

int main(void)
{
    MAN a, *pa;

    pa = &a;
    printf(" Size of structure 'a' = %zu\n", sizeof(a));
    printf(" Size of pointer  'pa' = %zu\n", sizeof(pa));
    printf(" Address of  pa    = %p\n", pa);
    printf(" Address of (pa+1) = %p\n", pa + 1);

    return 0;
}

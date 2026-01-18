#include <stdio.h>
#include <string.h>

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
    strcpy(pa->name, "TriOne");
    pa->kor = 87;
    pa->eng = 90;
    pa->math = 75;
    pa->total = pa->kor + pa->eng + pa->math;
    pa->ave = pa->total / 3;
    printf(" Name    : %s\n", pa->name);
    printf(" Korean  = %d\n", pa->kor);
    printf(" English = %d\n", pa->eng);
    printf(" Math    = %d\n", pa->math);
    printf(" Total   = %d\n", pa->total);
    printf(" Average = %3.2f\n", pa->ave);

    return 0;
}

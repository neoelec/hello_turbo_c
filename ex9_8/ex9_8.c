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
    strcpy(a.name, "TriOne");
    a.kor = 87;
    a.eng = 90;
    a.math = 75;
    a.total = a.kor + a.eng + a.math;
    a.ave = a.total / 3;
    printf(" Name    = %s\n", (*pa).name);
    printf(" Korean  = %d\n", (*pa).kor);
    printf(" English = %d\n", (*pa).eng);
    printf(" Math    = %d\n", (*pa).math);
    printf(" Total   = %d\n", (*pa).total);
    printf(" Average = %3.2f\n", (*pa).ave);

    return 0;
}

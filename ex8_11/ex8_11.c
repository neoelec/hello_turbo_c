#include <stdio.h>

int main(void)
{
    int **dptr, *ptr, i;

    i = 10;
    ptr = &i;
    dptr = &ptr;

    printf("  i = %4d  , *ptr = %4d , **dptr = %4d\n", i, *ptr, **dptr);
    printf(" &i = %4p  ,  ptr = %4p ,  *dptr = %4p\n", &i, ptr, *dptr);
    printf("             &ptr = %4p ,   dptr = %4p\n", &ptr, dptr);

    return 0;
}

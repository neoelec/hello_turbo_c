#include <stdio.h>

int main(void)
{
    printf(" Line : %d\n", __LINE__);
    printf(" File : %s\n", __FILE__);
    printf(" Date : %s\n", __DATE__);
    printf(" Time : %s\n", __TIME__);
#if defined(__TINY__)
    printf(" The memory model is Tiny.\n");
#elif defined(__SMALL__)
    printf(" The memory model is Small.\n");
#else
    printf(" Other memory model.\n");
#endif

    return 0;
}

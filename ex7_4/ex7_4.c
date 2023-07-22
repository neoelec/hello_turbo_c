#include <stdio.h>

int main(void)
{
    printf("Line-number : %d  Filename : %s\n", __LINE__, __FILE__);
#line 100 "MAIN.C"
#
    printf("Line-number : %d  Filename : %s\n", __LINE__, __FILE__);

    return 0;
}

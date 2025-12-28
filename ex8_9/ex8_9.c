#include <stdio.h>

int main(void)
{
    char *string[] = { "Jee kwung wuk", "lim chai sung", "kim ung suk" };
    int i;

    for (i = 0; i < 3; i++) {
        printf(" string[%d]  Address : %p , String : \"%s\"\n", i, string[i],
               string[i]);
    }

    return 0;
}

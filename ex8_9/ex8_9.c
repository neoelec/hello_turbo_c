#include <stdio.h>

int main(void)
{
    char string[][20] = {
        "lee kwung wuk",
        "lim chae sung",
        "kim ung sung",
    };
    int i;

    for (i = 0; i < 3; i++) {
        printf(" string[%d]  Address : %p , String : \"%s\"\n", i, string[i],
               string[i]);
    }

    return 0;
}

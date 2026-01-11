#include <stdio.h>

int main(void)
{
    char string[][20] = {
        "lee kwung wuk",
        "lim chae sung",
        "kim ung suk",
    };

    printf(" Total used memory : %u\n", sizeof(string));

    return 0;
}

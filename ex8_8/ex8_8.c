#include <stdio.h>
#include <string.h>

int main(void)
{
    char string[][20] = {
        "lee kwung wuk",
        "lim chae sung",
        "kim ung sung",
    };
    int ps, sum = 0, i;

    ps = sizeof(string);
    printf(" Total used memory : %d\n", ps);

    for (i = 0; i < 3; i++) {
        sum += strlen(string[i]) + 1;
    }

    printf(" String constant size : %d\n", sum);
    printf(" Total used memory : %d\n", ps + sum);

    return 0;
}

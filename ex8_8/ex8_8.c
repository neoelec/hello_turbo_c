#include <stdio.h>
#include <string.h>

int main(void)
{
    char *string[] = {
        "lee kyung wuk",
        "lim chae sung",
        "kim ung suk",
    };
    int ps, sum = 0, i;

    ps = sizeof(string);
    printf(" String pointer size : %d\n", ps);

    for (i = 0; i < 3; i++) {
        sum += strlen(string[i]) + 1;
    }

    printf(" String constant size : %d\n", sum);
    printf(" Total used memory : %d\n", ps + sum);

    return 0;
}

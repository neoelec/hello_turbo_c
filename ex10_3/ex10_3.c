#include <conio.h>
#include <stdio.h>

int main(void)
{
    char str[20];

    str[0] = 18;
    cgets(str);
    printf("\n%d characters   :  %s\n", str[1], &str[2]);

    return 0;
}

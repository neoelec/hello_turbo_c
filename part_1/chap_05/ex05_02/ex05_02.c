#include <stdio.h>

int main(void)
{
    int i;

    for (printf("\nexp1"), i = 0; printf("\n    exp2"), i < 5;
         printf("\n        exp3"), i++) {
        printf("%8d", i);
    }

    return 0;
}

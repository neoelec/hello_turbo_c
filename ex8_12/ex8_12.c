#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;

    printf(" Program name %s\n", argv[0]);

    if (argc < 2) {
        printf(" argument is not exist!!\n");
    } else {
        for (i = 1; i < argc; i++) {
            printf(" Argument %d i s %s\n", i, argv[i]);
        }
    }

    return 0;
}

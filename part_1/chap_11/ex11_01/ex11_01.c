#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int ch;

    if (argc != 2) {
        printf("USAGE : ex11_1 filename.ext\n");
        exit(-1);
    }

    if ((fp = fopen(argv[1], "r+")) == NULL) {
        printf("File open error : %s\n\a", argv[1]);
        exit(-1);
    }

    printf("FileView : %s.\n\n", argv[1]);

    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }

    fclose(fp);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *srcfp, *destfp;
    int ch;

    if (argc != 3) {
        printf("USAGE : ex11_2 srcfile destfile\n");
        exit(-1);
    }

    if ((srcfp = fopen(argv[1], "rb")) == NULL) {
        printf("File open error : %s\n\a", argv[1]);
        exit(-1);
    }

    if ((destfp = fopen(argv[2], "wb")) == NULL) {
        printf("File creation error : %s\n\a", argv[2]);
        exit(-1);
    }

    printf("FileCopy %s to %s.\n\n", argv[1], argv[2]);

    while ((ch = fgetc(srcfp)) != EOF) {
        fputc(ch, destfp);
    }

    fclose(srcfp);
    fclose(destfp);

    return 0;
}

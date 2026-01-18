#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    char str[128];
    int line = 0;

    if ((fp = fopen("test.txt", "w")) == NULL) {
        printf("File open error ...\n");
        exit(-1);
    }

    for (;;) {
        gets(str);

        if (str[0] == '\0') {
            break;
        }

        line++;
        fprintf(fp, "%3d : %s\n", line, str);
    }

    fclose(fp);

    return 0;
}

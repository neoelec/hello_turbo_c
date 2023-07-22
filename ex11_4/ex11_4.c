#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mystruct {
    int num;
    char name[10];
    char tel[10];
};

int main(void)
{
    FILE *fp;
    struct mystruct s, d;

    if ((fp = fopen("test.tst", "wb+")) == NULL) {
        printf("File open error . . .");
        exit(-1);
    }

    s.num = 1;
    strcpy(s.name, "Mr.Kim");
    strcpy(s.tel, "123-4567");

    fwrite(&s, sizeof(s), 1, fp);
    fseek(fp, 0, SEEK_SET);
    fread(&d, sizeof(d), 1, fp);
    printf(" Number : %8d\n Name : %10s\n Tel : %11s\n", d.num, d.name, d.tel);

    fclose(fp);

    return 0;
}

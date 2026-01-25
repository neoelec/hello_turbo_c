#include <ctype.h>
#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXKEY 5
static char KEY[MAXKEY] = { 0x34, 0xf2, 0x12, 0x0c, 0xeb };

static unsigned int count = 0;

void code(char *input, char *output);

void code(char *input, char *output)
{
    FILE *fp1, *fp2;
    char ch;

    if ((fp1 = fopen(input, "rb")) == NULL) {
        printf("cannot open input file\n");
        exit(EXIT_FAILURE);
    }

    if ((fp2 = fopen(output, "wb")) == NULL) {
        printf("cannot open output file\n");
        exit(EXIT_FAILURE);
    }

    do {
        ch = getc(fp1);
        ch ^= KEY[count % MAXKEY];

        if (feof(fp1)) {
            break;
        }

        putc(ch, fp2);
        count++;
    } while (!ferror(fp1) && !ferror(fp2));

    fclose(fp1);
    fclose(fp2);
}

int main(int argc, char *argv[])
{
    printf("CIPHER (C)CSLIM V2.0\n");

    if (argc != 3) {
        printf("Usage : cipher2 <infile> <outfile>\n");
        exit(EXIT_FAILURE);
    }

    if (!strcmp(argv[1], argv[2])) {
        printf("\a\nFile name must be different ...\n");
        exit(EXIT_SUCCESS);
    }

    code(argv[1], argv[2]);
    printf("\nComplete !\n");

    return 0;
}

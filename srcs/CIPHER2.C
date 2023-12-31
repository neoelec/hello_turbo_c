#include <ctype.h>
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

	fp1 = fopen(input, "rb");
	if (fp1 == NULL) {
		printf("cannot open input file\n");
		exit(1);
	}

	fp2 = fopen(output, "wb");
	if (fp2 == NULL) {
		printf("cannot open output file\n");
		exit(1);
	}

	do {
		ch = getc(fp1);
		ch ^= KEY[count % MAXKEY];
		if (feof(fp1))
			break;

		putc(ch, fp2);
	} while (!ferror(fp1) && !ferror(fp2));

	close(fp1);
	close(fp2);
}

void main(int argc, char *argv[])
{
	printf("CIPHER (C)CSLIM V2.0\n");
	if (argc != 3) {
		printf("Usage : cipher2 <infile> <outfile>\n");
		exit(1);
	}

	if (!strcmp(argv[1], argv[2])) {
		printf("\07\nFile name must be different ...\n");
		exit(0);
	}

	code(argv[1], argv[2]);

	printf("\nCompelete !\n");
}

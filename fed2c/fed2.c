#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *str, *out;
    int ch, col = 0, n = 0, cont;
    int info[4];

    if (argc < 3) {
        puts(" \a Usage : C:\\>fed2c <File1> <File2>\n");
        exit(255);
    }

    str = fopen(argv[1], "rb");
    out = fopen(argv[2], "wt");

    fseek(str, 28, SEEK_SET);
    info[0] = fgetc(str);
    info[1] = fgetc(str);
    info[2] = fgetc(str);
    info[3] = fgetc(str);
    cont = (info[2] / 8 + 1) * (info[3] + 1);
    fprintf(out, "\t\t[][%d] = { {\n\t\t", cont + 4);
    fprintf(out, "0x%02x, 00, 0x%02x, 00,\n\t\t", info[2], info[3]);

    while ((ch = fgetc(str)) != EOF) {
        fprintf(out, "0x%02x, ", ch);

        if (++col == 10) {
            col = 0;
            fprintf(out, "\n\t\t");
        }

        if (++n == cont) {
            col = n = 0;
            fseek(out, -2L, SEEK_END);
            fprintf(out, " } , {\n\t\t");
            fprintf(out, "0x%02x, 00, Ox%02x, 00,\n\t\t", info[2], info[3]);
        }
    }

    fseek(out, -33L, SEEK_END);
    fprintf(out, " } };\n\032");
    fclose(str);
    fclose(out);

    return 0;
}

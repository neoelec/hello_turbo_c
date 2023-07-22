#include <conio.h>
#include <stdio.h>

int main(void)
{
    FILE *ff;
    int ch;

    ff = fopen("EX9_5.TXT", "rb");

    while ((ch = fgetc(ff)) != EOF) {
        putch(ch);
    }

    fclose(ff);
    printf("\nProcessing end.  press any key!!");
    getch();

    return 0;
}

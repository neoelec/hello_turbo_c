#include <conio.h>
#include <stdio.h>

int main(void)
{
    double x = 123.456;
    char *str = "12345678901234567890";

    clrscr();

    printf("|%d|\n", 123);
    printf("|%5d|\n", 123);
    printf("|%05d|\n", 123);
    printf("|%-5d|\n", 123);
    printf("|%-05d|\n\n", 123);

    printf("%u\n\n", -1);

    printf("|%x|\n", 456);
    printf("|%7x|\n", 456);
    printf("|%07x|\n", 456);
    printf("|%-7x|\n", 456);
    printf("|%#7x|\n", 456);
    printf("|%#7X|\n\n", 456);

    printf("|%10ld|\n", 789L);
    printf("|%10ld|\n", 123456789);
    printf("|%7ld|\n\n", 123456789);

    printf("Press any key to next page . . .");

    getch();
    clrscr();

    printf("|%f|\n", x);
    printf("|%12.4f|\n", x);
    printf("|%12.1f|\n", x);

    printf("|%-12.4f|\n", x);
    printf("|%012.4f|\n\n", x);

    printf("|%e|\n", x);
    printf("|%14.8e|\n", x);
    printf("|%14.5e|\n", x);
    printf("|%-14.8e|\n", x);
    printf("|%014.8e|\n\n", x);

    printf("|%g|\n", x);
    printf("|%14.8g|\n", x);
    printf("|%14.5g|\n", x);
    printf("|%-14.8g|\n", x);
    printf("|%014.8g|\n\n", x);

    printf("%g\n", 12e-1);
    printf("%g\n\n", 12e+10);

    printf("Press any key to next page . . .");

    getch();
    clrscr();

    printf("|%s|\n", str);
    printf("|%15s|\n", str);
    printf("|%30s|\n", str);
    printf("|%-30s|\n", str);
    printf("|%30.10s|\n", str);
    printf("|%-30.10s|\n", str);
    printf("|%8.8s|\n", str);

    return 0;
}

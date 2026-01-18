#include <stdio.h>

void print_back(void);

void print_back(void)
{
    int ch;

    if ((ch = getchar()) != '\n') {
        print_back();
    }

    putchar(ch);
}

int main(void)
{
    printf("Enter a line : ");
    print_back();

    return 0;
}

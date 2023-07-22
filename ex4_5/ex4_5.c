#include <stdio.h>

int main(void)
{
    int a;
    char b[40];

    printf("The size of some fundamental types is computed.\n\n");
    printf("       char:%3zu byte\n", sizeof(char));
    printf("      short:%3zu bytes\n", sizeof(short));
    printf("        int:%3zu bytes\n", sizeof(int));
    printf("       long:%3zu bytes\n", sizeof(long));
    printf("   unsigned:%3zu bytes\n", sizeof(unsigned));
    printf("      float:%3zu bytes\n", sizeof(float));
    printf("     double:%3zu bytes\n", sizeof(double));
    printf("long double:%3zu bytes\n", sizeof(long double));
    printf("The variable a has %3zu bytes.\n", sizeof(a));
    printf("The variable b has %3zu bytes.\n", sizeof(b));

    return 0;
}

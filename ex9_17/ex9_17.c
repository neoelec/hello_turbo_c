#include <stdio.h>

void seperate_code(const unsigned code);

int main(void)
{
    seperate_code(30);
    seperate_code(0x8c40);
    seperate_code(0x9d40);

    return 0;
}

void seperate_code(const unsigned code)
{
    union h {
        unsigned in;
        struct {
            unsigned last : 5;
            unsigned middle : 5;
            unsigned first : 5;
            unsigned flag : 1;
        } bit_field;
    } c;

    c.in = code;

    if (c.bit_field.flag == 1) {
        printf(" First code = %u\n", c.bit_field.first);
        printf(" Middle code = %u\n", c.bit_field.middle);
        printf(" Last code = %u\n", c.bit_field.last);
    } else {
        printf(" This code(%u) is not hangul code !!!\n", code);
    }

    printf("\n");
}

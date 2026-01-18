#include <stdio.h>

typedef struct {
    char name[20];
    char addr[40];
    char tel[10];
} INFO;

struct p {
    int x, y;
} point = { 320, 240 };

struct p dot[2] = {
    { 100, 200 },
    { 300, 400 },
};

int main(void)
{
    INFO data = {
        "Jun S.C.",
        {
            'S',
            'e',
            'o',
            'u',
            'l',
            ' ',
            'K',
            'o',
            'r',
            'e',
            'a',
            '\0',
        },
        "738-5230",
    };

    printf(" x : %d y : %d\n", point.x, point.y);
    printf(" Name    : %s\n", data.name);
    printf(" Address : %s\n", data.addr);
    printf(" Tel.    : %s\n", data.tel);

    return 0;
}

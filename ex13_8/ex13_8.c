#include <conio.h>
#include <graphics.h>

void FillStyleDemo(void);
void FillPatternDemo(void);

void FillStyleDemo(void)
{
    int h, w, style;
    int i, j, x, y;

    w = 2 * ((getmaxx() + 1) / 13);
    h = 2 * ((getmaxy() - 10) / 10);

    x = w / 2;
    y = h / 2;
    style = 0;

    for (j = 0; j < 3; j++) {
        for (i = 0; i < 4; i++) {
            setfillstyle(style, getmaxcolor());
            bar(x, y, x + w, y + h);
            rectangle(x, y, x + w, y + h);
            style++;
            x += (w / 2) * 3;
        }

        x = w / 2;
        y += (h / 2) * 3;
    }

    getch();
}

void FillPatternDemo(void)
{
    int style;
    int h, w;
    int x, y, i, j;
    static char patterns[][8] = {
        { 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55 },
        { 0x33, 0x33, 0xCC, 0xCC, 0x33, 0x33, 0xCC, 0xCC },
        { 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0 },
        { 0x00, 0x10, 0x28, 0x44, 0x28, 0x10, 0x00, 0x00 },
        { 0x00, 0x70, 0x20, 0x27, 0x24, 0x24, 0x07, 0x00 },
        { 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00 },
        { 0x00, 0x00, 0x3C, 0x3C, 0x3C, 0x3C, 0x00, 0x00 },
        { 0x00, 0x7E, 0x7E, 0x7E, 0x7E, 0x7E, 0x7E, 0x00 },
        { 0x00, 0x00, 0x22, 0x08, 0x00, 0x22, 0x1C, 0x00 },
        { 0xFF, 0x7E, 0x3C, 0x18, 0x18, 0x3C, 0x7E, 0xFF },
        { 0x00, 0x10, 0x10, 0x7C, 0x10, 0x10, 0x00, 0x00 },
        { 0x00, 0x42, 0x24, 0x18, 0x18, 0x24, 0x42, 0x00 },
    };

    w = 2 * ((getmaxx() + 1) / 13);
    h = 2 * ((getmaxy() - 10) / 10);
    x = w / 2;
    y = h / 2;
    style = 0;

    for (j = 0; j < 3; j++) {
        for (i = 0; i < 4; i++) {
            setfillpattern(&patterns[style][0], getmaxcolor());
            bar(x, y, x + w, y + h);
            rectangle(x, y, x + w, y + h);
            style++;
            x += (w / 2) * 3;
        }

        x = w / 2;
        y += (h / 2) * 3;
    }

    getch();
}

int main(void)
{
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:/TC/BGI");
    FillStyleDemo();
    FillPatternDemo();
    closegraph();

    return 0;
}

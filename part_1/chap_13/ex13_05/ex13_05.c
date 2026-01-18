#include <conio.h>
#include <graphics.h>

int main(void)
{
    int style;
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:/TC/BGI");

    for (style = SOLID_LINE; style <= DASHED_LINE; style++) {
        setlinestyle(style, 0, NORM_WIDTH);
        line(style * 40 + 50, 50, style * 40 + 50, getmaxy() - 50);
    }

    for (style = SOLID_LINE; style <= DASHED_LINE; style++) {
        setlinestyle(style, 0, THICK_WIDTH);
        line(style * 40 + 250, 50, style * 40 + 250, getmaxy() - 50);
    }

    setlinestyle(USERBIT_LINE, 0xaaaa, NORM_WIDTH);
    line(500, 50, 500, getmaxy() - 50);
    setlinestyle(USERBIT_LINE, 0xf18f, NORM_WIDTH);
    line(540, 50, 540, getmaxy() - 50);
    setlinestyle(USERBIT_LINE, 0xf0ff, NORM_WIDTH);
    line(580, 50, 580, getmaxy() - 50);

    getch();
    closegraph();

    return 0;
}

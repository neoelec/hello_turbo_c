#include <conio.h>
#include <graphics.h>

char *fname[] = {
    "DEFAULT font",    "TRIPLEX font", "SMALL font",
    "SANS SERIF font", "GOTHIC font",
};

int main(void)
{
    int gd = DETECT, gm;
    int style, midx, midy;
    int size = 1;

    initgraph(&gd, &gm, "C:/TC/BGI");

    midx = getmaxx() / 2 - 100;
    midy = getmaxy() / 2 - 20;

    for (style = DEFAULT_FONT; style <= GOTHIC_FONT; style++) {
        cleardevice();

        if (style == TRIPLEX_FONT) {
            size = 4;
        }

        settextstyle(style, HORIZ_DIR, size);
        outtextxy(midx, midy, fname[style]);
        getch();
    }

    closegraph();

    return 0;
}

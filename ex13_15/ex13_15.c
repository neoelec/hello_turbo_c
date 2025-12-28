#include <conio.h>
#include <graphics.h>
#include <stdio.h>

char *hjust[] = { "LEFT_TEXT", "CENTER_TEXT", "RIGHT_TEXT" };

char *vjust[] = { "BOTTOM_TEXT", "CENTER_TEXT", "TOP_TEXT" };

int main(void)
{
    int gd = DETECT, gm;
    int midx, midy, hj, vj;
    char msg[80];

    initgraph(&gd, &gm, "C:/TC/BGI");

    midx = getmaxx() / 2;
    midy = getmaxy() / 2;

    for (hj = LEFT_TEXT; hj <= RIGHT_TEXT; hj++) {
        for (vj = LEFT_TEXT; vj <= RIGHT_TEXT; vj++) {
            cleardevice();
            settextjustify(hj, vj);

            sprintf(msg, "%s  %s", hjust[hj], vjust[vj]);

            line(midx - 4, midy, midx + 4, midy);
            line(midx, midy - 4, midx, midy + 4);

            outtextxy(midx, midy, msg);
            getch();
        }
    }

    closegraph();

    return 0;
}

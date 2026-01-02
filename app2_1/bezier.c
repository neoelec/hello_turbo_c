#include <graphics.h>

#include "bezier. h"

typedef struct {
    int x, y;
} POINT;

int cycle[] = { 3, 6, 12, 24, 48, 96 };
int count[] = { 0, 1, 2, 4, 8, 16 };

void calcbe(POINT *p, int n)
{
    int i;
    POINT tpo[2];

    for (i = 0; i < 2; i++) {
        tpo[i] = *(p + i + 1);
    }

    (p + 1)->x = (p->x + tpo[0].x) >> 1;
    (p + 1)->y = (p->y + tpo[0].y) >> 1;
    (p + cycle[n] + 2)->x = (tpo[1].x + (p + cycle[n + 1])->x) >> 1;
    (p + cycle[n] + 2)->y = (tpo[1].y + (p + cycle[n + 1])->y) >> 1;
    (p + 2)->x = ((p + 1)->x + ((tpo[0].x + tpo[1].x) >> 1)) >> 1;
    (p + 2)->y = ((p + 1)->y + ((tpo[0].y + tpo[1].y) >> 1)) >> 1;
    (p + cycle[n] + 1)->x =
        ((p + cycle[n] + 2)->x + ((tpo[0].x + tpo[1].x) >> 1)) >> 1;
    (p + cycle[n] + 1)->y =
        ((p + cycle[n] + 2)->y + ((tpo[0].y + tpo[1].y) >> 1)) >> 1;
    (p + cycle[n])->x = ((p + 2)->x + (p + cycle[n] + 1)->x) >> 1;
    (p + cycle[n])->y = ((p + 2)->y + (p + cycle[n] + 1)->y) >> 1;
}

void bezier(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    int step, c, i, stc = 4;
    POINT be_line[49];

    be_line[0].x = x1;
    be_line[0].y = y1;
    be_line[1].x = x2;
    be_line[1].y = y2;
    be_line[2].x = x3;
    be_line[2].y = y3;
    be_line[cycle[stc]].x = x4;
    be_line[cycle[stc]].y = y4;

    for (step = 0; step < stc; step++) {
        for (c = 0; c < count[step + 1]; c++) {
            calcbe(&be_line[c * count[stc - step] * 6], stc - step - 1);
        }
    }

    moveto(be_line[0].x, be_line[0].y);

    for (i = 1; i < cycle[stc] + 1; i++) {
        lineto(be_line[i].x, be_line[i].y);
    }
}

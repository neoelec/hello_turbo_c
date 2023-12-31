#include <graphics.h>
#include <stdio.h>

void p_bar(int x1, int y1, int x2, int y2, int gd);

char pattern[8] = { 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55 };

void main(void)
{
	int gd = DETECT, gm, x_len, y_len, i, j;
	char ch[40];

	initgraph(&gd, &gm, "");

	x_len = getmaxx() / 3;
	y_len = getmaxy() / 3;

	for (i = j = 0; i < x_len; i += (x_len / 4), j += (y_len / 4))
		p_bar(i, j, i + x_len, j + y_len, gd);

	sprintf(ch, "Cubic Effect !!");
	outtextxy(i, j, ch);

	getch();
	closegraph();
}

void p_bar(int x1, int y1, int x2, int y2, int gd)
{
	if (gd == HERCMONO) {
		setfillpattern(pattern, getmaxcolor());
		bar(x1, y1, x2, y2);
	} else {
		setfillstyle(SOLID_FILL, LIGHTGRAY);
		bar(x1, y1, x2, y2);
	}

	setcolor(WHITE);
	rectangle(x1, y1, x2, y2);
	setcolor(BLACK);
	line(x2, y1, x2, y2);
	line(x1, y2, x2, y2);
}

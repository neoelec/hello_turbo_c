#include <conio.h>
#include <graphics.h>

void main(void)
{
	int gd = DETECT, gm;

	initgraph(&gd, &gm, "");

	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);

	settextjustify(LEFT_TEXT, TOP_TEXT);
	outtextxy(50, 30, "Normal Size");

	setusercharsize(1, 3, 1, 1);
	outtextxy(50, 80, "Short Size");

	setusercharsize(3, 1, 1, 1);
	outtextxy(50, 140, "Wide Size");

	setusercharsize(2, 1, 5, 1);
	outtextxy(50, 150, "Long Size");

	getch();
	closegraph();
}

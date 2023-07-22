#include <conio.h>
#include <graphics.h>

void main(void)
{
	int gd = DETECT, gm;
	char buffer[8] = { 0x00, 0x70, 0x20, 0x27, 0x24, 0x24, 0x07, 0x00 };

	initgraph(&gd, &gm, "");

	setcolor(getmaxcolor());
	rectangle(0, 0, getmaxx(), getmaxy());
	setfillpattern(buffer, getmaxcolor());
	floodfill(1, 1, getmaxcolor());

	getch();
	closegraph();
}

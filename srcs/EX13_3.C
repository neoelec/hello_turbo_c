#include <conio.h>
#include <graphics.h>
#include <stdlib.h>

void main(void)
{
	int color;
	int gd = DETECT, gm;

	initgraph(&gd, &gm, "");
	while (!kbhit()) {
		color = random(getmaxcolor() + 1);
		setcolor(color);
		line(random(getmaxx()), random(getmaxy()), random(getmaxx()), random(getmaxy()));
		circle(random(getmaxy()), random(getmaxy()), random(1000));
	}
	closegraph();
}

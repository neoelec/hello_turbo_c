#include <graphics.h>
#include <stdlib.h>

void main(void)
{
	int eangle;
	struct arccoordstype ai;
	int gd = DETECT, gm;

	initgraph(&gd, &gm, "");

	randomize();

	while (!kbhit()) {
		setcolor(random(getmaxcolor()) + 1);
		eangle = random(358) + 1;
		arc(random(getmaxx()), random(getmaxy()), random(eangle), eangle, random(100));
		getarccoords(&ai);
		line(ai.x, ai.y, ai.xstart, ai.ystart);
		line(ai.x, ai.y, ai.xend, ai.yend);
	}

	closegraph();
}

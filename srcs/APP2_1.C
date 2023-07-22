#include <conio.h>
#include <dos.h>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

#include "bezier.h"

void main(void)
{
	int gd = DETECT, gm, n = 0;

	initgraph(&gd, &gm, "");
	randomize();

	while (!kbhit()) {
		setcolor(random(16));
		bezier(random(getmaxx()), random(getmaxy()), random(getmaxx()), random(getmaxy()),
		       random(getmaxx()), random(getmaxy()), random(getmaxx()), random(getmaxy()));

		delay(200);

		n++;
		if (n >= 10) {
			cleardevice();
			n = 0;
		}
	}

	closegraph();
}

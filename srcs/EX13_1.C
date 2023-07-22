#include <conio.h>
#include <graphics.h>
#include <stdio.h>

void main(void)
{
	int gd = DETECT, gm;

	initgraph(&gd, &gm, "");
	if (graphresult() != grOk) {
		printf("graphics error !\n");
		exit(1);
	}

	line(0, 0, getmaxx(), getmaxy());
	getch();
	closegraph();
}

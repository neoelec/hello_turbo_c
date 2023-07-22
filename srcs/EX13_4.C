#include <conio.h>
#include <graphics.h>

void main(void)
{
	int i, j;
	int gd = DETECT, gm;

	initgraph(&gd, &gm, "");

	rectangle(0, 0, getmaxx(), getmaxy());

	for (i = 0, j = 20; i < getmaxx(); i += 100, j += 100) {
		moveto(i, j);

		linerel(100, 0);
		linerel(-100, 50);
		linerel(50, -70);
		linerel(50, 70);
		linerel(-100, -50);
	}

	getch();
	closegraph();
}

#include <graphics.h>
#include <stdio.h>

void main(void)
{
	int i, menuchoice = 0, barchoice = 0;
	char ch[40];

	char *title[] = {
		" Disk ",
		" Directory ",
		" View ",
		" Quit! ",
	};
	char *disk[] = {
		" Change disk" " Rescan disk",
		" Volume label",
	};
	char *drive[] = {
		" A: drive ",
		" B: drive ",
		" C: drive ",
		" D: drive ",
	};
	char *directory[] = {
		" Print tree",
		" Rescan",
		" Delete",
	};
	char *view[] = {
		" 25 lines",
		" 40 lines",
		" 50 lines",
	};
	int gd = DETECT, gm;

	initgraph(&gd, &gm, "");

	make_top(title, "divq", 4);
	make_menu(1, disk, "crv", 3, 0, 0);
	make_menu(2, directory, "prd", 3, 0, 1);
	make_menu(3, view, "245", 3, 0, 2);
	make_menu(5, drive, "abcd", 4, 1, 0);

	while (barchoice != -1) {
		pulldriver(&menuchoice, &barchoice, gd);

		sprintf(ch, "Frame = %d Menu Number = %d", menuchoice, barchoice);
		setfillstyle(SOLID_FILL, BLACK);
		bar(100, getmaxy() / 2, 100 + 40 * 8, getmaxy() / 2 + 8);
		outtextxy(100, getmaxy() / 2, ch);
	}

	closegraph();
}

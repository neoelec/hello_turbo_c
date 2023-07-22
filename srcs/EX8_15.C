#include <stdio.h>

void main(void)
{
	char string[][15] = { "Load", "Save", "Pick", "New" };
	int i;

	for (i = 0; i < 4; i++)
		printf("%s\n", string[i]);
}

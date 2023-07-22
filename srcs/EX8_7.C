#include <stdio.h>

void main(void)
{
	char string[][20] = {
		"lee kwung wuk",
		"lim chae sung",
		"kim ung sung",
	};

	printf(" Total used memory : %zu\n", sizeof(string));
}

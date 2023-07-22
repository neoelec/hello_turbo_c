#include <stdio.h>

void main(void)
{
	char hello[] = { 'H', 'e', 'l', 'l', 'o', ' ',
		'W', 'o', 'r', 'l', 'd', '\n', '\0'
	};

	printf("Hello, World\n");
	printf(hello);
}

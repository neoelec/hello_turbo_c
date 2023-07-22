#include <stdio.h>

void main(void)
{
	int a;

	do {
		scanf("%d", &a);
		printf("%d\n", a * a);
	} while (a != 0);
}

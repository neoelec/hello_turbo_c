#include <stdio.h>

void main(void)
{
	int height, base;
	float extent;

	base = 5;
	printf(" Enter the length of the base:");
	scanf("%d", &height);
	extent = 0.5 * base * height;
	printf(" The extent o a triangle is %f", extent);
}

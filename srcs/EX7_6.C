#include <stdio.h>

void main(void)
{
	enum { zero,
		one, two, three, four, five,
		six, seven, eight, nine, ten
	} su;

	su = two + six;
	printf(" Two + Six = %d\n", su);
}

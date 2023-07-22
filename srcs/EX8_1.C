#include <stdio.h>

void main(void)
{
	int i, *iptr;

	i = 5;
	iptr = &i;
	printf(" iptr = %p\n", iptr);
	iptr++;
	printf(" iptr = %p\n", iptr);
	iptr = iptr + 2;
	printf(" iptr = %p\n", iptr);
}

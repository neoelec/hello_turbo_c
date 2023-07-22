#include <stdio.h>

int func1(int val);

void main(void)
{
	int i;
	int (*fptr)(int i);

	i = 123;
	fptr = func1;
	i = (*fptr) (i);
	printf(" i = %d\n", i);
}

int func1(int val)
{
	printf(" val is %d\n", val);

	return 999;
}

#include <stdio.h>

struct da {
	int x, y;
};

int total(struct da tot);

void main(void)
{
	struct da val = { 10, 30 };
	int sum = 0;

	sum = total(val);
	printf(" Sum = %d\n", sum);
}

int total(struct da tot)
{
	return (tot.x + tot.y);
}

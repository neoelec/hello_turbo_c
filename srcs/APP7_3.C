#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sort_function(const void *a, const void *b);

char list[5][4] = { "cat", "car", "cab", "cap", "can" };

void main(void)
{
	size_t x;

	qsort(list, 5, sizeof(list[0]), sort_function);
	for (x = 0; x < 5; x++)
		printf("%s\n", list[x]);
}

int sort_function(const void *a, const void *b)
{
	return strcmp(a, b);
}

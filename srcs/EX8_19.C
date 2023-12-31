#include <stdio.h>
#include <stdlib.h>

int func1(const void *ptr1, const void *ptr2);

void main(void)
{
	int table[] = { 11, 22, 33, 44, 55, 66, 77, 88, 99 };
	char buff[20], *ptr;
	int key;
	size_t n, w;

	w = sizeof(table[0]);
	n = sizeof(table) / w;
	printf(" Enter a value: ");
	while ((key = atoi(gets(buff))) != 0) {
		ptr = (char *)bsearch(&key, table, n, w, func1);
		if (ptr != NULL)
			printf(" Match on %d and %d\n\n", key, *ptr);
		else
			printf(" Enter a value: ");
	}

	printf(" Process ending....!!\n");
}

int func1(const void *ptr1, const void *ptr2)
{
	return (*(const int *)ptr1 - *(const int *)ptr2);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *colors[10] = { "Red", "Blue", "Green" };

int ncolors = 3;

int colorscmp(const void *arg1, const void *arg2)
{
    return strcmp(*(const char **)arg1, *(const char **)arg2);
}

int addelem(char *key)
{
    int oldn = ncolors;

    lsearch(key, colors, (size_t *)&ncolors, sizeof(char *), colorscmp);

    return ncolors == oldn;
}

int main(void)
{
    int i;
    char *key = "Purple";

    if (addelem(key)) {
        printf("%s already in colors table\n", key);
    } else {
        strcpy(colors[ncolors - 1], key);
        printf("%s added to colors table\n", key);
    }

    printf("The colors:\n");

    for (i = 0; i < ncolors; i++) {
        printf("%s\n", colors[i]);
    }

    return 0;
}

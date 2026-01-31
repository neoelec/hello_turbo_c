#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_MAX 100
#define ENG_MAX 30
#define KOR_MAX 50

int word_sort(void);
int read_data(struct word *ps0);
struct word *b_search(struct word *idx[], int count, char *key);
void qs(struct word *idx[], int left, int right);

struct word {
    char english[ENG_MAX];
    char korean[KOR_MAX];
} dictionary[WORD_MAX];

struct word *index[WORD_MAX];

int main(void)
{
    int max;
    char word[ENG_MAX];
    struct word *pos;

    max = word_sort();

    while (1) {
        printf("\nEnter the word: ");

        if (*gets(word) == '\0') {
            break;
        }

        pos = b_search(index, max, word);

        if (pos != NULL) {
            printf("\n[ %-30s ]\n", pos->korean);
        } else {
            puts("The word is not found !");
        }
    }

    puts("End..");

    return 0;
}

int word_sort(void)
{
    int maximum, i;

    maximum = read_data(dictionary);

    for (i = 0; i < maximum; i++) {
        index[i] = &dictionary[i];
    }

    qs(index, 0, maximum - 1);

    return maximum;
}

int read_data(struct word *ps)
{
    FILE *data;
    int i;

    if ((data = fopen("DICTION.TXT", "r+")) == NULL) {
        puts("DICTION.TXT reading error!");
        exit(EXIT_SUCCESS);
    }

    for (i = 0; i < WORD_MAX; i++, ps++) {
        if (fgets(ps->english, ENG_MAX, data) == NULL) {
            break;
        }

        *strchr(ps->english, '\n') = '\0';

        fgets(ps->korean, KOR_MAX, data);
        *strchr(ps->korean, '\n') = '\0';
    }

    return i;
}

struct word *b_search(struct word *idx[], int count, char *key)
{
    int condition;
    struct word **mid, **low = &idx[0], **high = &idx[count - 1];

    while (low <= high) {
        mid = low + (high - low) / 2;
        condition = strcmp(key, (*mid)->english);

        if (condition < 0) {
            high = mid - 1;
        } else if (condition > 0) {
            low = mid + 1;
        } else {
            return *mid;
        }
    }

    return NULL;
}

void qs(struct word *idx[], int left, int right)
{
    int i = left, j = right + 1;
    char *pivot;
    struct word *temp, *location;

    pivot = idx[left]->english;
    location = idx[left];

    if (left < right) {
        do {
            do {
                j++;
            } while (strcmp(idx[i]->english, pivot) < 0);

            do {
                j--;
            } while (strcmp(idx[j]->english, pivot) > 0);

            if (i < j) {
                temp = idx[i];
                idx[i] = idx[j];
                idx[j] = temp;
            }
        } while (i < j);

        idx[left] = idx[j];
        idx[j] = location;

        qs(idx, left, j - 1);
        qs(idx, j + 1, right);
    }
}

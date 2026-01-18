#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char ch;
    struct node *next;
} SLNODE;

SLNODE *shead, *stail;

SLNODE *search(SLNODE *node, char key);
void addsl(SLNODE **head, SLNODE **tail, char element);
void delsl(SLNODE **head, SLNODE **tail, char key);
void list(SLNODE *node);

int main(void)
{
    int selec;

    puts("\n1. Add character\n2. Delete character");
    puts("3. Find character\n4. List of all");
    puts("5. Exit\nEnter number: ");
    scanf("%d", &selec);

    while (selec != 5) {
        while (getchar() != '\n') {
            continue;
        }

        switch (selec) {
        case 1:
            printf("Enter character to add: ");
            addsl(&shead, &stail, getchar());
            break;

        case 2:
            printf("Enter character to delete: ");
            delsl(&shead, &stail, getchar());
            break;

        case 3:
            printf("Enter character to find: ");

            if (search(shead, getchar())) {
                puts("It is found");
            } else {
                puts("It is not found");
            }

            break;

        case 4:
            list(shead);
            break;
        }

        puts("\n1. Add character\n2. Delete character");
        puts("3. Find character\n4. List of all");
        puts("5. Exit\nEnter number: ");
        scanf("%d", &selec);
    }

    puts("End..");

    return 0;
}

SLNODE *search(SLNODE *node, char key)
{
    while (node != NULL) {
        if (node->ch == key) {
            return node;
        }

        node = node->next;
    }

    return NULL;
}

void addsl(SLNODE **head, SLNODE **tail, char element)
{
    SLNODE *node;

    if ((node = (SLNODE *)malloc(sizeof(SLNODE))) == NULL) {
        printf(" Out of memory.\n");

        return;
    }

    if (*tail != NULL) {
        (*tail)->next = node;
    }

    if (*head == NULL) {
        *head = node;
    }

    *tail = node;
    (*tail)->next = NULL;

    (*tail)->ch = element;
}

void delsl(SLNODE **head, SLNODE **tail, char key)
{
    SLNODE *node = *head, *last = NULL;

    while (node != NULL) {
        if (node->ch == key) {
            break;
        }

        last = node;
        node = node->next;
    }

    if (node == NULL) {
        puts("\nNot found");

        return;
    }

    if (node != *head) {
        last->next = node->next;
    } else {
        *head = (node->next != NULL) ? node->next : NULL;
    }

    if (node == *tail) {
        *tail = last;
    }

    free(node);
}

void list(SLNODE *node)
{
    puts("\nList of nodes");

    while (node != NULL) {
        printf("%3c", node->ch);
        node = node->next;
    }
}

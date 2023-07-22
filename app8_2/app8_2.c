#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAXSIZE 128

typedef struct dnode {
    char ch[MAXSIZE];
    struct dnode *prev, *next;
} DNODE;

DNODE *head;

DNODE *find(char *key);
void insnode(char *element);
void delnode(DNODE **head, char *element);
void list(DNODE *head);

int main(void)
{
    char ch[MAXSIZE];
    int selec;

    puts("\n1. Insert string\n2. Delete string");
    puts("3. List of all nodes\n4. Exit\nEnter number: ");
    scanf("%d", &selec);

    while (selec != 4) {
        while (getchar() != '\n') {
            continue;
        }

        switch (selec) {
        case 1:
            printf("Enter string to add: ");
            insnode(gets(ch));
            break;

        case 2:
            printf("Enter string to delete: ");
            delnode(&head, gets(ch));
            break;

        case 3:
            list(head);
            break;
        }

        puts("\n1. Insert string\n2. Delete string");
        puts("3. List of all nodes\n4. Exit\nEnter number: ");
        scanf("%d", &selec);
    }

    puts("End..");

    return 0;
}

DNODE *find(char *key)
{
    char found = FALSE;
    DNODE *node;

    node = head;

    do {
        if (strcmp(key, node->ch) < 0) {
            found = TRUE;
        } else {
            node = node->next;
        }
    } while (!found && node != head);

    return node;
}

void insnode(char *element)
{
    DNODE *ins = NULL, *node;

    node = (DNODE *)malloc(sizeof(DNODE));

    if (node == NULL) {
        puts("Out of memory!");

        return;
    }

    strcpy(node->ch, element);

    if (head == NULL) {
        head = node;
        head->prev = head->next = node;
    } else {
        ins = find(node->ch);
        node->prev = ins->prev;
        ins->prev = node;
        node->next = ins;
        node->prev->next = node;

        if (strcmp(node->ch, head->ch) < 0) {
            head = node;
        }
    }
}

void delnode(DNODE **head, char *element)
{
    char found = FALSE;
    DNODE *del = *head;

    do {
        if (strcmp(element, del->ch) == 0) {
            found = TRUE;
        } else {
            del = del->next;
        }
    } while (!found && del != *head);

    if (found == FALSE) {
        puts("It is not found");

        return;
    }

    if (del == *head) {
        if (del == del->next) {
            *head = NULL;
            free(del);

            return;
        } else {
            *head = del->next;
        }
    }

    del->next->prev = del->prev;
    del->prev->next = del->next;
    free(del);
}

void list(DNODE *node)
{
    puts("List of all nodes");

    if (node != NULL) {
        do {
            printf("%s\n", node->ch);
            node = node->next;
        } while (node != node);
    }
}

#include <alloc.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct chnode {
    int info;
    struct chnode *prev, *next;
} NODE;

NODE *stack, *qhead, *qtail;

NODE *enqueue(int element, NODE *tail);
NODE *dequeue(int *element, NODE *head);
NODE *push(int element, NODE *top);
NODE *pop(int *element, NODE *top);

int main(void)
{
    char data[5];
    int value;

    clrscr();
    puts("Queue and stacks\n");
    puts("Enter some numbers:\n");

    while (*gets(data) != '\0') {
        value = atoi(data);
        qtail = enqueue(value, qtail);

        stack = push(value, stack);
    }

    puts("\n\nYour input taken from the queue:\n");

    while (qhead != NULL) {
        qhead = dequeue(&value, qhead);
        printf("%5d", value);
    }

    puts("\nYour input taken from the stack:\n");

    while (stack != NULL) {
        stack = pop(&value, stack);
        printf("%5d", value);
    }

    puts("\n");

    return 0;
}

NODE *enqueue(int element, NODE *tail)
{
    NODE *newtail;

    newtail = malloc(sizeof(NODE));
    newtail->info = element;

    if (tail) {
        tail->next = newtail;
    }

    newtail->prev = tail;
    newtail->next = NULL;

    if (qhead == NULL) {
        qhead = newtail;
    }

    return newtail;
}

NODE *dequeue(int *element, NODE *head)
{
    NODE *newhead = NULL;

    if (head) {
        *element = head->info;
        newhead = head->next;
        newhead->prev = NULL;
        free(head);
    } else {
        *element = NULL;
    }

    return newhead;
}

NODE *push(int element, NODE *top)
{
    NODE *newtop;

    newtop = malloc(sizeof(NODE));
    newtop->info = element;

    if (top) {
        top->prev = newtop;
    }

    newtop->next = top;
    newtop->prev = NULL;

    return newtop;
}

NODE *pop(int *element, NODE *top)
{
    NODE *newtop = NULL;

    if (top) {
        *element = top->info;
        newtop = top->next;
        newtop->prev = NULL;
        free(top);
    } else {
        *element = NULL;
    }

    return newtop;
}

#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"

enum Boolean { FALSE, TRUE };
Hashtable_type HT;

int Hash(char *str)
{
    int h = 0;

    while (*str) {
        h += *str++;
    }

    return abs(h % HASHSIZE);
}

void inithash(void)
{
    int i;

    for (i = 0; i < HASHSIZE; i++) {
        HT[i] = NULL;
    }
}

void insert(Node_type node)
{
    Node_type *Nodeptr;
    int h;

    Nodeptr = malloc(sizeof(Node_type));
    *Nodeptr = node;
    h = Hash(Nodeptr->username);
    Nodeptr->next = HT[h];
    HT[h] = Nodeptr;
}

void newuser(void)
{
    Node_type node;

    while (TRUE) {
        *node.username = NULL;
        *node.password = NULL;

        while (!(*node.username)) {
            printf("\n# User name (max 8 character) : ");
            gets(node.username);
        }

        while (!(*node.password)) {
            strcpy(node.password, getpass("# password (max 8 character) : "));
        }

        insert(node);
        printf(" continue (y/n)? ");

        if (toupper(getch()) != 'Y') {
            return;
        }
    }
}

int search(Node_type node)
{
    Node_type *Nodeptr;
    int h;

    h = Hash(node.username);
    Nodeptr = HT[h];

    while (Nodeptr) {
        if (!strcmp(Nodeptr->username, node.username)) {
            if (!strcmp(Nodeptr->password, node.password)) {
                return TRUE;
            } else {
                return FALSE;
            }
        }

        Nodeptr = Nodeptr->next;
    }

    return FALSE;
}

void testlogin(void)
{
    Node_type node;

    printf("\n\n\n *** WELCOME TO HYCSE BBS ! ***\n");

    while (TRUE) {
        printf("\nUSERNAME : ");
        gets(node.username);
        strcpy(node.password, getpass("PASSWORD : "));

        if (search(node)) {
            printf("\nsuccessful login !\n");
        } else {
            printf("\n\alogin failure !\n");
        }

        printf("*** repeat login test (y/n)? ");

        if (toupper(getche()) != 'Y') {
            return;
        }
    }
}

int main(void)
{
    char ch;

    inithash();

    while (TRUE) {
        clrscr();
        printf("\n*** Hash table test Program ***\n");
        printf("   (1) Insert New user.\n");
        printf("   (2) Test LOGIN.\n");
        printf("   (3) End program.\n");
        printf("   Enter number(1-3) : ");

        ch = getche();

        if (ch == '1') {
            newuser();
        } else if (ch == '2') {
            testlogin();
        } else if (ch == '3') {
            break;
        }
    }

    return 0;
}

#ifndef __HASH_H__
#define __HASH_H__

#define MAXNAME 15
#define MAXPASS 8
#define HASHSIZE 97

typedef struct node_tag {
    char username[MAXNAME + 1];
    char password[MAXPASS + 1];
    struct node_tag *next;
} Node_type;

typedef Node_type *Hashtable_type[HASHSIZE];

#endif /* ifndef __HASH_H__ */

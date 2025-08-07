#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
} DNode;

void doubly_linked_list_menu(void);

#endif

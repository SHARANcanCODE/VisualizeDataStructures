#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void singly_linked_list_menu(void);

#endif

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct BTNode {
    int data;
    struct BTNode* left;
    struct BTNode* right;
} BTNode;

void binary_tree_menu(void);

#endif

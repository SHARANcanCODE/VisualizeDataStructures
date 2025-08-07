#include <stdio.h>
#include <stdlib.h>
#include <binarytree.h>
#include "utils.h"

static BTNode* root = NULL;

static BTNode* create_node(int val) {
    BTNode* node = (BTNode*)malloc(sizeof(BTNode));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

static void insert_node(BTNode** node, int val) {
    if (*node == NULL) {
        *node = create_node(val);
    } else {
        if ((*node)->left == NULL)
            insert_node(&((*node)->left), val);
        else if ((*node)->right == NULL)
            insert_node(&((*node)->right), val);
        else
            insert_node(&((*node)->left), val);  // simple insertion for demo
    }
}

static void print_tree(BTNode *node, int space) {
    if (node == NULL)
        return;

    space += 5;

    print_tree(node->right, space);

    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%d\n", node->data);

    print_tree(node->left, space);
}

static void menu_insert(void) {
    int val;
    printf("Enter value to insert in Binary Tree: ");
    scanf("%d", &val);
    insert_node(&root, val);
    printf("Value inserted.\n");
    pause();
}

void binary_tree_menu(void) {
    int choice;
    do {
        clear_screen();
        printf("Binary Tree\n");
        printf("1. Insert\n2. Display\n0. Return to main menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        while(getchar() != '\n');
        switch(choice) {
            case 1: menu_insert(); break;
            case 2:
                clear_screen();
                printf("Binary Tree visualization:\n");
                print_tree(root, 0);
                pause();
                break;
            case 0: break;
            default: printf("Invalid choice!\n"); pause();
        }
    } while(choice != 0);
}

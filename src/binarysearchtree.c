#include <stdio.h>
#include <stdlib.h>
#include <binarysearchtree.h>
#include "utils.h"

static BSTNode* root = NULL;

static BSTNode* create_node(int val) {
    BSTNode* node = (BSTNode*)malloc(sizeof(BSTNode));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

static BSTNode* insert_node(BSTNode* node, int val) {
    if (node == NULL) {
        return create_node(val);
    }
    if (val < node->data) {
        node->left = insert_node(node->left, val);
    } else if (val > node->data) {
        node->right = insert_node(node->right, val);
    }
    return node;
}

static BSTNode* min_value_node(BSTNode* node) {
    BSTNode* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

static BSTNode* delete_node(BSTNode* root, int val) {
    if (root == NULL) return root;
    if (val < root->data)
        root->left = delete_node(root->left, val);
    else if (val > root->data)
        root->right = delete_node(root->right, val);
    else {
        if (root->left == NULL) {
            BSTNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            BSTNode* temp = root->left;
            free(root);
            return temp;
        }
        BSTNode* temp = min_value_node(root->right);
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }
    return root;
}

static void print_tree(BSTNode* node, int space) {
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
    printf("Enter value to insert in BST: ");
    scanf("%d", &val);
    root = insert_node(root, val);
    printf("Value inserted.\n");
    pause();
}

static void menu_delete(void) {
    int val;
    printf("Enter value to delete from BST: ");
    scanf("%d", &val);
    root = delete_node(root, val);
    printf("Value deleted if present.\n");
    pause();
}

void binary_search_tree_menu(void) {
    int choice;
    do {
        clear_screen();
        printf("Binary Search Tree\n");
        printf("1. Insert\n2. Delete\n3. Display\n0. Return to main menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        while(getchar() != '\n');
        switch(choice) {
            case 1: menu_insert(); break;
            case 2: menu_delete(); break;
            case 3:
                clear_screen();
                printf("BST visualization:\n");
                print_tree(root,0);
                pause();
                break;
            case 0: break;
            default: printf("Invalid choice!\n"); pause();
        }
    } while(choice != 0);
}

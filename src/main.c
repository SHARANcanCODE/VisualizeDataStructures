#include <stdio.h>
#include <array.h>
#include <stack.h>
#include "queue.h"
#include "singly_linked_list.h"
#include "doubly_linked_list.h"
#include "binarytree.h"
#include "binarysearchtree.h"
#include "heap.h"
#include "graph.h"
#include "utils.h"

int main(void) {
    int choice;
    do {
        clear_screen();
        printf("Visualizing Data Structures Using C with ASCII Art\n\n");
        printf("Select a data structure to interact with:\n");
        printf("1. Array\n");
        printf("2. Stack\n");
        printf("3. Queue\n");
        printf("4. Singly Linked List\n");
        printf("5. Doubly Linked List\n");
        printf("6. Binary Tree\n");
        printf("7. Binary Search Tree\n");
        printf("8. Heap (Min Heap)\n");
        printf("9. Graph (Adjacency List + Traversals)\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        while(getchar() != '\n');

        switch(choice) {
            case 1: array_menu(); break;
            case 2: stack_menu(); break;
            case 3: queue_menu(); break;
            case 4: singly_linked_list_menu(); break;
            case 5: doubly_linked_list_menu(); break;
            case 6: binary_tree_menu(); break;
            case 7: binary_search_tree_menu(); break;
            case 8: heap_menu(); break;
            case 9: graph_menu(); break;
            case 0: printf("Goodbye!\n"); break;
            default: 
                printf("Invalid choice!\n");
                pause();
        }
    } while(choice != 0);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"
#include "utils.h"

static DNode* head = NULL;

static void display_list(void) {
    clear_screen();
    printf("Doubly Linked List visualization:\n");
    printf("NULL <-> ");
    DNode* temp = head;
    while(temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

static void insert_node(void) {
    int val;
    printf("Enter value to insert at end: ");
    scanf("%d", &val);
    DNode* new_node = (DNode*)malloc(sizeof(DNode));
    new_node->data = val;
    new_node->next = NULL;
    if (head == NULL) {
        new_node->prev = NULL;
        head = new_node;
    } else {
        DNode* temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
        new_node->prev = temp;
    }
    display_list();
    pause();
}

static void delete_node(void) {
    if(head == NULL) {
        printf("List empty!\n");
        pause();
        return;
    }
    int val;
    printf("Enter value to delete: ");
    scanf("%d", &val);

    DNode* temp = head;
    while(temp != NULL && temp->data != val) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Value not found.\n");
    } else {
        if(temp->prev != NULL)
            temp->prev->next = temp->next;
        else
            head = temp->next;

        if(temp->next != NULL)
            temp->next->prev = temp->prev;

        free(temp);
        printf("Node deleted.\n");
    }
    display_list();
    pause();
}

void doubly_linked_list_menu(void) {
    int choice;
    do {
        clear_screen();
        printf("Doubly Linked List\n");
        printf("1. Insert (end)\n2. Delete (by value)\n3. Display\n0. Return to main menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        while(getchar() != '\n');
        switch(choice) {
            case 1: insert_node(); break;
            case 2: delete_node(); break;
            case 3: display_list(); pause(); break;
            case 0: break;
            default: printf("Invalid choice!\n"); pause();
        }
    } while(choice != 0);
}

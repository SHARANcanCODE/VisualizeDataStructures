#include <stdio.h>
#include <array.h>
#include <string.h>
#include "utils.h"

static int arr[MAX_SIZE];  
static int size = 0;

static void display_array(void) {
    clear_screen();
    printf("Array visualization:\n");
    printf("Index: ");
    for (int i = 0; i < size; i++) {
        printf("[%d]  ", i);
    }
    printf("\nValues: ");
    for (int i = 0; i < size; i++) {
        printf(" %d   ", arr[i]);
    }
    printf("\n");
}

static void insert_element(void) {
    if (size >= MAX_SIZE) {
        printf("Array is full!\n");
        pause();
        return;
    }
    int val;
    printf("Enter value to insert: ");
    scanf("%d", &val);
    arr[size++] = val;
    display_array();
    pause();
}

static void delete_element(void) {
    if (size == 0) {
        printf("Array is empty!\n");
        pause();
        return;
    }
    int index;
    printf("Enter index to delete (0 to %d): ", size - 1);
    scanf("%d", &index);
    if (index < 0 || index >= size) {
        printf("Invalid index.\n");
    } else {
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        printf("Element deleted.\n");
    }
    display_array();
    pause();
}

void array_menu(void) {
    int choice;
    do {
        clear_screen();
        printf("Array Data Structure\n");
        printf("1. Insert\n2. Delete\n3. Display\n0. Return to main menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        while(getchar() != '\n'); // flush newline

        switch (choice) {
            case 1: insert_element(); break;
            case 2: delete_element(); break;
            case 3:
                display_array();
                pause();
                break;
            case 0: break;
            default:
                printf("Invalid choice!\n");
                pause();
        }
    } while(choice != 0);
}

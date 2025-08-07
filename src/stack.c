#include <stdio.h>
#include <stack.h>
#include "utils.h"

static int stack[STACK_MAX];
static int top = -1;

static void display_stack(void) {
    clear_screen();
    printf("Stack visualization (Top at the top):\n");
    for (int i = top; i >= 0; i--) {
        printf(" --- \n| %2d |\n --- \n", stack[i]);
    }
    if (top == -1) {
        printf("[Empty Stack]\n");
    }
}

static void push(void) {
    if (top >= STACK_MAX - 1) {
        printf("Stack Overflow!\n");
        pause();
        return;
    }
    int val;
    printf("Enter value to push: ");
    scanf("%d", &val);
    stack[++top] = val;
    display_stack();
    pause();
}

static void pop(void) {
    if (top == -1) {
        printf("Stack Underflow!\n");
        pause();
        return;
    }
    printf("Popped value: %d\n", stack[top--]);
    display_stack();
    pause();
}

void stack_menu(void) {
    int choice;
    do {
        clear_screen();
        printf("Stack Data Structure\n");
        printf("1. Push\n2. Pop\n3. Display\n0. Return to main menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        while(getchar() != '\n'); // flush newline

        switch(choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3:
                display_stack();
                pause();
                break;
            case 0: break;
            default:
                printf("Invalid choice!\n");
                pause();
        }
    } while(choice != 0);
}

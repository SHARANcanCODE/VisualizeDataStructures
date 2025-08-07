#include <stdio.h>
#include "queue.h"
#include "utils.h"

static int queue[QUEUE_MAX];
static int front = -1;
static int rear = -1;

static void display_queue(void) {
    clear_screen();
    printf("Queue visualization (Front -> Rear):\n");
    if (front == -1) {
        printf("[Empty Queue]\n");
        return;
    }
    printf("Front -> ");
    for (int i = front; i <= rear; i++) {
        printf("| %d | -> ", queue[i]);
    }
    printf("NULL\n");
}

static void enqueue(void) {
    if (rear == QUEUE_MAX - 1) {
        printf("Queue Full!\n");
        pause();
        return;
    }
    int val;
    printf("Enter value to enqueue: ");
    scanf("%d", &val);
    if (front == -1) front = 0;
    queue[++rear] = val;
    display_queue();
    pause();
}

static void dequeue(void) {
    if (front == -1 || front > rear) {
        printf("Queue Empty!\n");
        pause();
        return;
    }
    printf("Dequeued value: %d\n", queue[front++]);
    if (front > rear) {
        front = rear = -1;
    }
    display_queue();
    pause();
}

void queue_menu(void) {
    int choice;
    do {
        clear_screen();
        printf("Queue Data Structure\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n0. Return to main menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        while(getchar() != '\n'); // flush newline

        switch(choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3:
                display_queue();
                pause();
                break;
            case 0: break;
            default:
                printf("Invalid choice!\n");
                pause();
        }
    } while(choice != 0);
}

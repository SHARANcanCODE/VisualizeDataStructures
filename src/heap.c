#include <stdio.h>
#include "heap.h"
#include "utils.h"

static int heap[HEAP_MAX];
static int size = 0;

static void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

static void heapify_up(int index) {
    while(index > 0 && heap[(index - 1)/2] > heap[index]) {
        swap(&heap[(index - 1)/2], &heap[index]);
        index = (index - 1)/2;
    }
}

static void heapify_down(int index) {
    int smallest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;

    if (left < size && heap[left] < heap[smallest]) smallest = left;
    if (right < size && heap[right] < heap[smallest]) smallest = right;

    if (smallest != index){
        swap(&heap[index], &heap[smallest]);
        heapify_down(smallest);
    }
}

static void display_heap(int index, int space) {
    if (index >= size) return;

    space += 5;
    display_heap(2*index + 2, space);

    printf("\n");
    for(int i=5; i<space; i++)
        printf(" ");
    printf("%d\n", heap[index]);

    display_heap(2*index + 1, space);
}

static void insert_heap(int val) {
    if (size == HEAP_MAX) {
        printf("Heap is full!\n");
        return;
    }
    heap[size] = val;
    heapify_up(size);
    size++;
}

static int extract_min(void) {
    if (size <= 0) {
        printf("Heap is empty!\n");
        return -1;
    }
    int root_val = heap[0];
    heap[0] = heap[size -1];
    size--;
    heapify_down(0);
    return root_val;
}

void heap_menu(void) {
    int choice;
    int val;
    do {
        clear_screen();
        printf("Min Heap\n");
        printf("1. Insert\n2. Extract Min\n3. Display\n0. Return to main menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        while(getchar() != '\n');

        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insert_heap(val);
                printf("Value inserted.\n");
                pause();
                break;
            case 2:
                val = extract_min();
                if (val != -1)
                    printf("Extracted value: %d\n", val);
                pause();
                break;
            case 3:
                clear_screen();
                printf("Heap visualization:\n");
                display_heap(0, 0);
                pause();
                break;
            case 0: break;
            default:
                printf("Invalid choice!\n");
                pause();
        }
    } while(choice != 0);
}

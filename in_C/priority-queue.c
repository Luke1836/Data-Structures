#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct PriorityQueue {
    int elements[MAX_SIZE];
    int priorities[MAX_SIZE];
    int size;
};

void initialize(struct PriorityQueue* pq) {
    pq->size = 0;
}

void enqueue(struct PriorityQueue* pq, int element, int priority) {
    if (pq->size >= MAX_SIZE) {
        printf("Priority Queue is full, cannot enqueue more elements.\n");
        return;
    }

    // Insert the element and priority at the end of the arrays
    pq->elements[pq->size] = element;
    pq->priorities[pq->size] = priority;
    pq->size++;

    // Sort elements based on priorities in descending order
    for (int i = pq->size - 1; i > 0; --i) {
        if (pq->priorities[i] > pq->priorities[i - 1]) {
            // Swap elements
            int tempElement = pq->elements[i];
            int tempPriority = pq->priorities[i];
            pq->elements[i] = pq->elements[i - 1];
            pq->priorities[i] = pq->priorities[i - 1];
            pq->elements[i - 1] = tempElement;
            pq->priorities[i - 1] = tempPriority;
        } else {
            // Elements are in the correct order, break the loop
            break;
        }
    }
}

void dequeue(struct PriorityQueue* pq) {
    if (pq->size <= 0) {
        printf("Priority Queue is empty, cannot dequeue.\n");
        return;
    }

    // Remove the element with the highest priority (first element)
    printf("Dequeued Element: %d (Priority: %d)\n", pq->elements[0], pq->priorities[0]);

    // Shift remaining elements to fill the gap
    for (int i = 1; i < pq->size; ++i) {
        pq->elements[i - 1] = pq->elements[i];
        pq->priorities[i - 1] = pq->priorities[i];
    }
    pq->size--;
}

void display(struct PriorityQueue* pq) {
    printf("Priority Queue: ");
    for (int i = 0; i < pq->size; ++i) {
        printf("(%d, %d) ", pq->elements[i], pq->priorities[i]);
    }
    printf("\n");
}

int main() {
    struct PriorityQueue pq;
    initialize(&pq);

    int choice, element, priority;
    while (1) {
        printf("Priority Queue Operations:\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Display Priority Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &element);
                printf("Enter priority: ");
                scanf("%d", &priority);
                enqueue(&pq, element, priority);
                break;
            case 2:
                dequeue(&pq);
                break;
            case 3:
                display(&pq);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

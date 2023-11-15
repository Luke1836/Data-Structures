#include <stdio.h>
#include <stdlib.h>

// Define a Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to display the elements of the queue
void display(struct Node* front) {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");
    struct Node* current = front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to insert an element into the queue
struct Node* enqueue(struct Node* rear, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        return newNode;
    }

    rear->next = newNode;
    return newNode;
}

// Function to delete an element from the queue
struct Node* dequeue(struct Node* front) {
    if (front == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
        return NULL;
    }

    struct Node* temp = front;
    front = front->next;
    free(temp);
    return front;
}


void freeQueue(struct Node* front) {
    struct Node* current = front;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct Node* front = NULL; 
    struct Node* rear = NULL;  

    int choice, value;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue (Insert element)\n");
        printf("2. Dequeue (Delete element)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                rear = enqueue(rear, value);
                if (front == NULL) {
                    front = rear;
                }
                display(front);
                break;
            case 2:
                front = dequeue(front);
                display(front);
                break;
            case 3:
                display(front);
                break;
            case 4:
                freeQueue(front);
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

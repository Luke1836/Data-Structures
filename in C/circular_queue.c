#include <stdio.h>

#define MAX_SIZE 8

int circularQueue[MAX_SIZE];
int front = -1;
int rear = -1;

int isFull() {
    return ((rear + 1) % MAX_SIZE == front);
}

int isEmpty() {
    return (front == -1 && rear == -1);
}

void enqueue(int item) {
    if (isFull()) {
        printf("Queue is full. Cannot inserted element %d.\n", item);
    } else {
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }
        circularQueue[rear] = item;
        printf("Element %d inserted to the queue.\n", item);
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot delete element.\n");
    } else {
        int dequeuedItem = circularQueue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
        printf("Element %d deleted from the queue.\n", dequeuedItem);
    }
}

void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        int i = front;
        printf("Queue contents: ");
        do {
            printf("%d ", circularQueue[i]);
            i = (i + 1) % MAX_SIZE;
        } while (i != (rear + 1) % MAX_SIZE);
        printf("\n");
    }
}

int main() {
    int choice, element;
    
    do {
        printf("\n\t\t\t\tCircular Queue Operations\n");
        printf("1. Insert an Element\n");
        printf("2. Delete an Element\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to inserted: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                printf("The program execution has been terminated.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
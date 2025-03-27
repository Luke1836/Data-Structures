#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 8

int dequeue[MAX_SIZE];
int front = -1;
int rear = -1;
 
int isFull() {
    return ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1));
}

int isEmpty() {
    return (front == -1);
}

void insertFront(int item) {
    if (isFull()) {
        printf("Queue is full. Cannot insert element %d at the front.\n", item);
        exit(0); 
    } else {
        if (front == -1) {
            front = rear = 0;
        } else if (front == 0) {
            front = MAX_SIZE - 1;
        } else {
            front--;
        }
        dequeue[front] = item;
        printf("Element %d inserted at the front of the queue.\n", item);
    }
}

void insertRear(int item) {
    if (isFull()) {
        printf("Queue is full. Cannot insert element %d at the rear.\n", item);
    } else {
        if (front == -1) {
            front = rear = 0;
        } else if (rear == MAX_SIZE - 1) {
            rear = 0;
        } else {
            rear++;
        }
        dequeue[rear] = item;
        printf("Element %d inserted at the rear of the queue.\n", item);
    }
}

void deleteFront() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot delete from the front.\n");
    } else {
        int deletedItem = dequeue[front];
        if (front == rear) {
            front = rear = -1;
        } else if (front == MAX_SIZE - 1) {
            front = 0;
        } else {
            front++;
        }
        printf("Element %d deleted from the front of the queue.\n", deletedItem);
    }
}

void deleteRear() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot delete from the rear.\n");
    } else {
        int deletedItem = dequeue[rear];
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = MAX_SIZE - 1;
        } else {
            rear--;
        }
        printf("Element %d deleted from the rear of the queue.\n"
        , deletedItem);
    }
}

void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue contents: ");
        int i = front;
        do {
            printf("%d ", dequeue[i]);
            if (i == rear) {
                break;
            }
            i = (i + 1) % MAX_SIZE;
        } while (i != front);
        printf("\n");
    }
}

int main() {
    int choice, element;
    
    do {
        printf("\nDouble-Ended Queue Operations Menu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display Queue\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert at the front: ");
                scanf("%d", &element);
                insertFront(element);
                break;
            case 2:
                printf("Enter element to insert at the rear: ");
                scanf("%d", &element);
                insertRear(element);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                displayQueue();
                break;
            case 6:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 6);

    return 0;
}

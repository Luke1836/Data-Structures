#include <stdio.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int item) {
    if (top < MAX_SIZE - 1) {
        top++;
        stack[top] = item;
        printf("Element %d pushed to the stack.\n", item);
    } else {
        printf("Stack is full. Cannot push element %d.\n", item);
    }
}

void pop() {
    if (top > -1) {
        printf("Element %d popped from the stack.\n", stack[top]);
        top--;
    } else {
        printf("Stack is empty. Cannot pop an element.\n");
    }
}

void display() {
    if (top > -1) {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    } else { 
        printf("Stack is empty.\n");
    }
}

int main() {
    int size;
    printf("Enter the size of the stack: ");
    scanf("%d", &size);

    printf("Enter %d elements for the stack:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &stack[i]);
        top++;
    }

    int choice;
    do {
        printf("\nStack Operations Menu:\n");
        printf("1. Push Element\n");
        printf("2. Pop Element\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (top < MAX_SIZE - 1) {
                    int item;
                    printf("Enter element to push: ");
                    scanf("%d", &item);
                    push(item);
                } else {
                    printf("Stack is full. Cannot push more elements.\n");
                }
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
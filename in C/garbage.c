#include <stdio.h>
#include <stdlib.h>

struct LinkedList {
    int size;
    struct LinkedList* prev;
    struct LinkedList* next;
};

struct LinkedList* memoryHead = NULL;

void displayMemory() {
    struct LinkedList* current = memoryHead;
    printf("Memory Status:\n");

    while (current != NULL) {
        printf("Block Size: %d\n", current->size);
        current = current->next;
    }
    printf("\n");
}

void allocateMemory(int size) {
    struct LinkedList* newBlock = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    if (newBlock == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newBlock->size = size;
    newBlock->prev = NULL;
    newBlock->next = memoryHead;

    if (memoryHead != NULL) {
        memoryHead->prev = newBlock;
    }

    memoryHead = newBlock;
    printf("Allocated memory block of size %d.\n", size);
}

void deallocateMemory() {
    if (memoryHead == NULL) {
        printf("No memory block to deallocate.\n");
        return;
    }

    struct LinkedList* temp = memoryHead;
    memoryHead = temp->next;

    if (memoryHead != NULL) {
        memoryHead->prev = NULL;
    }

    free(temp);
    printf("Deallocated memory block.\n");
}

int main() {
    int choice, size;

    do {
        printf("1. Allocate Memory\n");
        printf("2. Deallocate Memory\n");
        printf("3. Display Memory Status\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter size to allocate: ");
                scanf("%d", &size);
                allocateMemory(size);
                break;

            case 2:
                deallocateMemory();
                break;

            case 3:
                displayMemory();
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

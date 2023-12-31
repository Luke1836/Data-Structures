#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Node {
    int data;
    struct Node* next;
};

struct HashTable {
    struct Node* table[SIZE];
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

// Function to insert using Chaining
void insertChaining(struct HashTable* hashTable, int key, int data) {
    int index = key % SIZE;
    struct Node* newNode = createNode(data);

    if (hashTable->table[index] == NULL) {
        hashTable->table[index] = newNode;
    } else {
        struct Node* temp = hashTable->table[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display using Chaining
void displayChaining(struct HashTable* hashTable) {
    printf("Hash Table (Chaining):\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d: ", i);
        struct Node* temp = hashTable->table[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Function to insert using Linear Probing
void insertLinearProbing(int hashTable[], int key, int data) {
    int index = key % SIZE;

    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;
    }

    hashTable[index] = data;
}

// Function to display using Linear Probing
void displayLinearProbing(int hashTable[]) {
    printf("Hash Table (Linear Probing):\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d: %d\n", i, hashTable[i]);
    }
}

int main() {
    // Initialize Chaining hash table
    struct HashTable chainingHashTable;
    for (int i = 0; i < SIZE; i++) {
        chainingHashTable.table[i] = NULL;
    }

    // Initialize Linear Probing hash table
    int linearProbingHashTable[SIZE];
    for (int i = 0; i < SIZE; i++) {
        linearProbingHashTable[i] = -1;
    }

    int choice, key, data;

    printf("\n1. Insert (Chaining)\n");
    printf("2. Display (Chaining)\n");
    printf("3. Insert (Linear Probing)\n");
    printf("4. Display (Linear Probing)\n");
    printf("5. Exit\n");
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter key and data for Chaining: ");
                scanf("%d %d", &key, &data);
                insertChaining(&chainingHashTable, key, data);
                break;

            case 2:
                displayChaining(&chainingHashTable);
                break;

            case 3:
                printf("Enter key and data for Linear Probing: ");
                scanf("%d %d", &key, &data);
                insertLinearProbing(linearProbingHashTable, key, data);
                break;

            case 4:
                displayLinearProbing(linearProbingHashTable);
                break;

            case 5:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

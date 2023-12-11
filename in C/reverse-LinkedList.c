#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Node* reverseLinkedList(struct Node* head) {
    struct Node *prev, *current, *next;
    prev = NULL;
    current = head;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev; // new head of the reversed list
}

void printLinkedList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeLinkedList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> NULL
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    printf("Original Linked List:\n");
    printLinkedList(head);

    // Reversing the linked list
    head = reverseLinkedList(head);

    printf("\nReversed Linked List:\n");
    printLinkedList(head);

    // Freeing the memory allocated for the linked list
    freeLinkedList(head);

    return 0;
}

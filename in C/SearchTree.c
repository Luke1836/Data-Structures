#include <stdio.h>
#include <stdlib.h>

typedef struct Node {   
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *insert(Node *root, int data)
 
{
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } 
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

Node *search(Node *root, int data)
{
    if (root == NULL || root->data == data) {
        return root;
    } 
    else if (data < root->data) {
        return search(root->left, data);
    } 
    else {
        return search(root->right, data);
    }
}

Node *deleteNode(Node *root, int data)
{
    if (root == NULL) {
        return NULL;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else
 
    if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } 
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } 
        else if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        } 
        else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        } 
        else {
            Node *temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

Node *minValueNode(Node *node)
{
    Node *current = node;
    while (current->left != NULL) 
        current = current->left;
    return current;
}

int main() {
    Node *root = NULL;
    int choice, data;

    while (1) {
        printf("\nBinary Search Tree Operations:");
        printf("\n1. Insert");
        printf("\n2. Search");
        printf("\n3. Delete");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: printf("Enter data to insert: ");
                    scanf("%d", &data);
                    root = insert(root, data);
                    printf("\n");
                    break;

            case 2: printf("Enter data to search for: ");
                    scanf("%d", &data);
                    printf("\n");
                    Node *foundNode = search(root, data);
                    if (foundNode) {
                        printf("Node with data %d found!\n", data);
                    } else {
                        printf("Node with data %d not found.\n", data);
                    }
                    break;

            case 3: printf("Enter data to delete: ");
                    scanf("%d", &data);
                    printf("\n");
                    root = deleteNode(root, data);
                    printf("Node deleted.\n");
                    break;

            case 4: exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }
    }
    printf("\n");
    return 0;
}
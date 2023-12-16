//Program to implement a binary tree using Linked Lists
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->right = newNode->left = NULL;
    return newNode;
}

struct Node *insertNode(struct Node *root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insertNode(root->left, value);
    else if (value > root->data)
        root->right = insertNode(root->right, value);

    return root;
}

struct Node *binSearch(struct Node *root, int value) {
    if (root == NULL || root->data == value)
        return root;

    if (value < root->data)
        return binSearch(root->left, value);

    return binSearch(root->right, value);
}

struct Node *findMinNode(struct Node *node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}

struct Node *deleteNode(struct Node *root, int value) {
    if (root == NULL)
        return root;

    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        struct Node *temp = findMinNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorderTraversal(struct Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node *root = NULL;
    int choice, value;

    printf("Binary Tree Operations\n1. Insert a node\n2. Delete a node\n3. Search a node\n4. Inorder Traversal\n5. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                break;

            case 2:
                printf("Enter the element to be deleted: ");
                scanf("%d", &value);
                printf("Node deletion in progress\n");
                root = deleteNode(root, value);
                break;

            case 3:
                printf("Enter the element to be searched: ");
                scanf("%d", &value);
                if (binSearch(root, value) != NULL)
                    printf("Element %d found in the tree.\n", value);
                else
                    printf("Element %d not found in the tree.\n", value);
                break;

            case 4:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 5:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice!!! Try Again.\n");
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

// Structure for a node in the binary tree
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Structure for a queue node
struct QueueNode {
    struct Node *node;
    struct QueueNode *next;
};

// Function to create a new node
struct Node *createNode(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to create an empty queue
struct QueueNode *createQueue() {
    return NULL;
}

// Function to check if the queue is empty
int isEmptyQueue(struct QueueNode *Q) {
    return Q == NULL;
}

// Function to enqueue a node
struct QueueNode *enQueue(struct QueueNode *Q, struct Node *node) {
    struct QueueNode *newNode = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    newNode->node = node;
    newNode->next = NULL;
    if (Q == NULL) {
        return newNode;
    }
    struct QueueNode *temp = Q;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return Q;
}

// Function to dequeue a node
struct Node *deQueue(struct QueueNode **Q) {
    if (isEmptyQueue(*Q)) {
        return NULL;
    }
    struct Node *node = (*Q)->node;
    struct QueueNode *temp = *Q;
    *Q = (*Q)->next;
    free(temp);
    return node;
}

// Function to delete the entire queue
void deleteQueue(struct QueueNode *Q) {
    while (!isEmptyQueue(Q)) {
        deQueue(&Q);
    }
}

// Function to insert a new node into the tree
struct Node *insertNode(struct Node *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    struct QueueNode *Q = createQueue();
    Q = enQueue(Q, root);
    while (!isEmptyQueue(Q)) {
        struct Node *temp = deQueue(&Q);
        if (temp->left) {
            Q = enQueue(Q, temp->left);
        } else {
            temp->left = createNode(value);
            deleteQueue(Q);
            return root;
        }
        if (temp->right) {
            Q = enQueue(Q, temp->right);
        } else {
            temp->right = createNode(value);
            deleteQueue(Q);
            return root;
        }
    }
    return root;
}

// Function to perform inorder traversal
void inorderTraversal(struct Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to perform preorder traversal
void preOrderTraversal(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Function to perform postorder traversal
void postOrderTraversal(struct Node *root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to search for a node in the tree
struct Node *searchNode(struct Node *root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    struct Node *left = searchNode(root->left, value);
    if (left != NULL) {
        return left;
    }
    return searchNode(root->right, value);
}

// Function to delete a leaf node from the tree
struct Node *deleteLeafNode(struct Node *root, int value) {
    if (root == NULL) {
        return NULL;
    }

    if (root->left == NULL && root->right == NULL && root->data == value) {
        free(root);
        return NULL;
    }
    root->left = deleteLeafNode(root->left, value);
    root->right = deleteLeafNode(root->right, value);
    return root;
}

int main() {
    struct Node *root = NULL;
    int choice, value;

    printf("Binary Tree Operations\n");
    printf("1. Insert a new node into the tree\n");
    printf("2. Inorder Traversal\n");
    printf("3. Preorder Traversal\n");
    printf("4. Postorder Traversal\n");
    printf("5. Delete a leaf node\n");
    printf("6. Exit\n");

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
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder Traversal: ");
                preOrderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postOrderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Enter the element to be deleted from the binary tree: ");
                scanf("%d", &value);
                printf("Node deletion in progress\n");
                root = deleteLeafNode(root, value);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
                printf("Try Again\n");
                break;
        }
    }
    return 0;
}
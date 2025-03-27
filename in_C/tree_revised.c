#include <stdio.h>
#include <stdlib.h>

struct Tree {
    int data;
    struct Tree *left;
    struct Tree *right;
};

struct Tree *root = NULL; // Initialize root to NULL

struct Tree *createNode(int data) {
    struct Tree *node = (struct Tree*)malloc(sizeof(struct Tree));
    if (!node) {
        printf("Memory Error!\n");
        return NULL;
    }
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Tree *searchParent(struct Tree *root, int key) {
    if (root == NULL || root->data == key)
        return root;
    struct Tree *left = searchParent(root->left, key);
    if (left)
        return left;
    return searchParent(root->right, key);
}

void insertNode(struct Tree *root, int key) {
    struct Tree *parent = NULL;
    parent = searchParent(root, key);

    if (parent != NULL) {
        int ch, data;
        if (parent->left == NULL || parent->right == NULL) {
            printf("Enter the data to be inserted: ");
            scanf("%d", &data);
            struct Tree *newNode = createNode(data);
            printf("1. Left\n2. Right\nEnter the position: ");
            scanf("%d", &ch);
            switch (ch) {
                case 1:
                    if (parent->left == NULL)
                        parent->left = newNode;
                    else
                        printf("Insertion is not possible as it is already occupied\n");
                    break;

                case 2:
                    if (parent->right == NULL)
                        parent->right = newNode;
                    else
                        printf("Insertion is not possible as it is already occupied\n");
                    break;

                default:
                    printf("Invalid choice\n");
                    return;
            }
        } else {
            printf("Both the child nodes are occupied\nInsertion is not possible\n");
            return;
        }
    } else {
        printf("The node doesn't exist\n");
        return;
    }
    return;
}

struct Tree *searchParent2(struct Tree *root, int key, struct Tree *parent)
{
    if(root == NULL) return root;
    if(root->data == key) return parent;

    struct Tree *left = searchParent2(root->left, key, root);
    if(left) 
        return left;
    return searchParent2(root->right, key, root); 
}

void deleteNode(struct Tree *root, int key) {
    struct Tree *parent = NULL;
    parent = searchParent2(root, key, parent);
    if (parent) {
        struct Tree *left = parent->left, *right = parent->right;
        if (left) {
            if (left->data == key) {
                if (left->left == NULL && left->right == NULL) {
                    parent->left = NULL;
                    free(left);
                    return;
                } else {
                    printf("The provided node is not a leaf node\n");
                    return;
                }
            }
        }

        if (right) {
            if (right->data == key) {
                if (right->left == NULL && right->right == NULL) {
                    parent->right = NULL;
                    free(right);
                    return;
                } else {
                    printf("The provided node is not a leaf node\n");
                    return;
                }
            }
        }
    } else {
        if (root->data == key) {
            printf("Cannot delete the root node\n");
            return;
        }

        printf("The node doesn't exist\n");
        return;
    }
}

void inorderTraversal(struct Tree *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main(void) {
    int choice, data, key;
    printf("Enter the root data: ");
    scanf("%d", &data);
    root = createNode(data);
    inorderTraversal(root);
    printf("\nOperations available\n1. Insertion into a binary tree\n2. Deletion from a binary Tree\n3. Inorder Traversal\n4. Exit\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the key (node to which you want to insert the value): ");
                scanf("%d", &key);
                insertNode(root, key);
                break;

            case 2:
                printf("Enter the key (node to be deleted): ");
                scanf("%d", &key);
                deleteNode(root, key);
                break;

            case 3:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\nTry Again\n");
        }
    } while (choice != 4);

    return 0;
}

//Program to implement a abinary tree using Linked Lists
#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node *left;
struct Node *right;
};
struct Node *createNode(int value)
{
struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = value;
newNode->right = newNode->left = NULL;
return newNode;
}

struct Node *insertNode(struct Node *root, int value)
{
struct Node *newNode = createNode(value);
if(value < root->data)
root->left = insertNode(root->left, value);
else if(value > root->left)
root->right = insertNode(root->right, value);
else
return root;
return root;
}
struct Node *binSearch(struct Node *root, int value)
{
    if(root == NULL || root->data == value)
    return root;
    if(value < root->data)
    return binSearch(root->left, value);
    return binSearch(root->right, value);   
}

struct Node *deleteNode(struct Node *root, int value)
{
    struct Node *temp;
    if(root == NULL)
        return NULL;
        if(value < root->data)
            root->left = deleteNode(root->left, value);
        else if(value > root->data)
            root->right = deleteNode(root->right, value);
        else
        {
        if(root->left == NULL)
            temp = root;

    }
}

int main()
{
    struct Node *root = NULL;
    int choice, value;
    printf("Binary Tree Operations\n1. Inserting a node into the tree\n2. Inorder Traversal\n3. Preorder Traversal\n4. Postorder Traversal\n5. Delete the node\n6. Exit\n");
    while(1)
    {
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1: printf("Enter the value to be inserted\n");
                scanf("%d", &value);
                root = insertNode(root, value);
                break;

        case 2: printf("Enter the element to be deleted from the binary tree\n");
                scanf("%d", &value);
                printf("Node deletion in progress\n");
                root = deleteNode(root, value);
                break;

        case 3: printf("Enter the element ot tbe searched.\n");
                scanf("%d", &value);
                root = binSearch(root, value);
                break;

        case 4: exit(0);
        default: printf("Invalid choice!!!\n Try Again\n");
        }
    }
    return 0;
}
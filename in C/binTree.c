//Program to implement a abinary tree using Linked Lists
#include <stdio.h>

#include <stdlib.h>
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next; 
};

struct Queue {
    struct Node *node;
    struct Queue *next;
};

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->right = newNode->left = NULL;
    return newNode;
}

struct Queue *createQueue()
{
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->next = NULL;
    return q;
}

int isEmpty(struct Queue *Q)
{
    return (Q->next == NULL);
}

struct Queue *enQueue(struct Queue *Q, struct Node *node) {
    if (Q == NULL) {
        Q = (struct Queue *)malloc(sizeof(struct Queue));
        Q->next = NULL;
        Q->node = node;
        return Q;
    }
    struct Queue *newNode = (struct Queue *)malloc(sizeof(struct Queue));
    newNode->next = NULL;
    newNode->node = node;
    Q->next = newNode;
    return Q;
}

struct Node *deQueue(struct Queue *Q) {
    struct Node *temp;
    if (Q->next == NULL) {
        return NULL;
    }
    temp = Q->next;
    Q->next = temp->next;
    return temp;
}

void deleteQueue(struct Queue *Q)
{
    struct Queue *temp;
    while(Q != NULL)
    {
        temp = Q;
        Q = Q->next;
        free(temp);
    }
}

struct Node *insertNode(struct Node *root, int value)
{
    struct Queue *Q = createQueue();
    struct Node *newNode = createNode(value), *temp;
    if(root == NULL)
        return newNode;
    Q = enQueue(Q, root);
    while(!isEmpty(Q))
    {
        temp = deQueue(Q);
        if(temp->left)
        {
            Q = enQueue(Q, temp->left);
        }
        else{
            temp->left = newNode;
            deleteQueue(Q);
            return root;
        }

        if(temp->right)
        {
            Q = enQueue(Q, temp->right);
        }
        else{
            temp->right = newNode;
            deleteQueue(Q);
            return root;
        }
    }
    return root;
}
void inorderTraversal(struct Node *root)
{
    if(root != NULL) {
        inorderTraversal(root->left);
        printf("%d\t", root->data);
        inorderTraversal(root->right);
    }
}
void preOrderTraversal(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d\t", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}
void postOrderTraversal(struct Node *root)
{
    if(root != NULL)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d\t", root->data);
    }

}
struct Node *deleteNode(struct Node *root) {
    if (root == NULL) {
        return NULL;
    }

    if (root->left == NULL && root->right == NULL) {
        free(root);
        return NULL;
    }

    root->left = deleteNode(root->left);
    root->right = deleteNode(root->right);
    return root;
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

            case 2: printf("Inorder Traversal:\n");
                    inorderTraversal(root);
                    printf("\n");
                    break;

            case 3: printf("Preorder Traversal: \n");
                    preOrderTraversal(root);
                    printf("\n");
                    break;

            case 4: printf("Postorder Traversa: \n");
                    postOrderTraversal(root);
                    printf("\n");
                    break;

            case 5: printf("Enter the element to be deleted from the binary tree\n");
                    scanf("%d", &value);
                    printf("Node deletion in progress\n");
                    root = deleteNode(root);
                    break;
            case 6: exit(0);
            default: printf("Invalid choice!!!\n Try Again\n");
        }
    }
    return 0;
}
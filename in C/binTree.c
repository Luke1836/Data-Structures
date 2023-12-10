//Program to implement a abinary tree using Linked Lists
#include <stdio.h>

#include <stdlib.h>
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Queue {
    int data;
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

struct Node *deQueue(struct Queue *Q)
{
    struct Node *temp;
    while(Q->next->next != NULL)
        Q = Q->next;
    temp = Q->next;
    free(Q->next);
    return temp;
}

struct Queue *enQueue(struct Queue *Q, struct Node *node)
{
    if(Q == NULL)
    {
        Q = node;
        return Q;
    }
    Q->next = node;
    return Q;
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
            deleteQueue();
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
struct Node *deleteNode(struct Node *root, int value)
{
    if(root == NULL)
    return NULL;
    struct Node *curr = root, *parent = NULL, *child, *successor;
    while(curr != NULL && curr->data != value)
    {
        parent = curr;
        if(curr->left != NULL)
            curr = curr->left;
        else
            curr = curr->right;

    }
    if(curr == NULL)
    {
        printf("The node is not found in the tree\n");
        return root;
    }
    if(curr->left == NULL || curr->right == NULL)
    {
        child = (curr->left != NULL) ? curr->left : curr->right;
        if(parent == NULL)
        {
            root->data = child->data;
            root->left = NULL;
            root->right = NULL;
            free(child);
        }
        else
        {
        if(parent->left == curr)
            parent->left = child;
        else
            parent->right = child;
        free(curr);
        }
    }
    else
    {
        successor = curr->right;
        while(successor->left != NULL)
            successor = successor->left;
        curr->data = successor->data;
        deleteNode(curr->right, successor->data);
    }
    printf("Deletion compeleted!\n");
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
                root = deleteNode(root, value);
                break;
            case 6: exit(0);
            default: printf("Invalid choice!!!\n Try Again\n");
        }
    }
    return 0;
}
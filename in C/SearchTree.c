#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct Node {
  int data;
  struct Node *left;
  struct Node *right;
} Node;

typedef struct Queue {
  Node *data[MAX_QUEUE_SIZE];
  int front;
  int rear;
} Queue;

Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}


Node *minValueNode(Node *node) {
  while (node->left != NULL) {
    node = node->left;
  }
  return node;
}

void displayLevelOrder(Node *root) {
  if (root == NULL) {
    return;
  }
  Queue q;
  q.front = 0;
  q.rear = -1;
  q.data[++q.rear] = root;

  while (q.front <= q.rear) {
    Node *temp = q.data[q.front];
    q.front++;

    printf("%d ", temp->data);

    if (temp->left) {
      q.data[++q.rear] = temp->left;
    }

    if (temp->right) {
      q.data[++q.rear] = temp->right;
    }
  }
  printf("\n");
}

Node *insert(Node *root, int data) {
  if (root == NULL) {
    return createNode(data);
  }

  if (data < root->data) {
    root->left = insert(root->left, data);
  } else if (data > root->data) {
    root->right = insert(root->right, data);
  } else {
    printf("Duplicate value! Node not inserted.\n");
  }

  displayLevelOrder(root);
  return root;
}

Node *search(Node *root, int data) {
  if (root == NULL || root->data == data) {
    return root;
  } else if (data < root->data) {
    return search(root->left, data);
  } else {
    return search(root->right, data);
  }
}

Node *deleteNode(Node *root, int data) {
  if (root == NULL) {
    return NULL;
  }

  if (data < root->data) {
    root->left = deleteNode(root->left, data);
  } else if (data > root->data) {
    root->right = deleteNode(root->right, data);
  } else {
    if (root->left == NULL && root->right == NULL) {
      free(root);
      return NULL;
    } else if (root->left == NULL) {
      Node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      Node *temp = root->left;
      free(root);
      return temp;
    } else {
      Node *temp = minValueNode(root->right);
      root->data = temp->data;
      root->right = deleteNode(root->right, temp->data);
    }
  }

  displayLevelOrder(root);
  return root;
}

int main() {
  Node *root = NULL;
  int choice, data;

  while (1) {
    printf("\nBinary Search Tree Operations:\n");
    printf("1. Insert\n");
    printf("2. Search\n");
    printf("3. Delete\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter data to insert: ");
        scanf("%d", &data);
        root = insert(root, data);
        break;
      case 2:
        printf("Enter data to search for: ");
        scanf("%d", &data);
        Node *foundNode = search(root, data);
        if (foundNode) {
          printf("Node with data %d found!\n", data);
        } else {
          printf("Node with data %d not found.\n", data);
        }
        break;
      case 3:
        printf("Enter data to delete: ");
        scanf("%d", &data);
        root = deleteNode(root, data);
        printf("Node deleted.\n");
        break;
      case 4:
        exit(0);
      default:
        printf("Invalid choice! Please try again.\n");
        break;
    }
  }
  return 0;
}
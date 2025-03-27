#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Structure for a node in the queue
struct Node {
    char data;
    struct Node* next;
};

// Structure for the queue
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to initialize a queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

struct Node* push(struct Node* top, char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = top;
    return newNode;
}

// Function to pop a character from the stack
char pop(struct Node** top) {
    if (*top == NULL) {
        return '\0'; // Empty stack
    }

    struct Node* temp = *top;
    char data = temp->data;
    *top = (*top)->next;
    free(temp);
    return data;
}

// Function to enqueue a character to the queue
void enqueue(struct Queue* queue, char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to dequeue a character from the queue
char dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        return '\0'; // Empty queue
    }

    struct Node* temp = queue->front;
    char data = temp->data;

    if (queue->front == queue->rear) {
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        queue->front = queue->front->next;
    }

    free(temp);
    return data;
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to determine the precedence of an operator
int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

// Function to convert infix expression to postfix expression
char* infixToPostfix(char* infix) {
    struct Queue* outputQueue = createQueue();
    struct Node* stack = NULL;

    for (int i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            enqueue(outputQueue, infix[i]);
        } else if (infix[i] == '(') {
            stack = push(stack, infix[i]);
        } else if (infix[i] == ')') {
            while (stack != NULL && stack->data != '(') {
                enqueue(outputQueue, pop(&stack));
            }
            if (stack != NULL && stack->data == '(') {
                stack = pop(&stack); // Pop and discard '('
            }
        } else if (isOperator(infix[i])) {
            while (stack != NULL && precedence(stack->data) >= precedence(infix[i])) {
                enqueue(outputQueue, pop(&stack));
            }
            stack = push(stack, infix[i]);
        }
    }

    while (stack != NULL) {
        enqueue(outputQueue, pop(&stack));
    }

    // Create a string to store the postfix expression
    char* postfix = (char*)malloc(MAX_SIZE * sizeof(char));
    int index = 0;

    // Dequeue characters from the output queue and store in the string
    while (outputQueue->front != NULL) {
        postfix[index++] = dequeue(outputQueue);
    }

    postfix[index] = '\0'; // Null-terminate the string
    return postfix;
}

int main() {
    char infixExpression[MAX_SIZE];

    printf("Enter infix expression: ");
    fgets(infixExpression, MAX_SIZE, stdin);

    // Remove newline character from the input
    infixExpression[strcspn(infixExpression, "\n")] = '\0';

    char* postfixExpression = infixToPostfix(infixExpression);

    printf("Infix Expression: %s\n", infixExpression);
    printf("Postfix Expression: %s\n", postfixExpression);

    free(postfixExpression); // Free the memory allocated for postfix expression

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack implementation
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

char pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->array[stack->top--];
    }
    return '$'; // Special character to indicate an empty stack
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    return 0;
}

void infixToPostfix(char* infix) {
    struct Stack* stack = createStack(strlen(infix));
    int i, j = 0;

    for (i = 0; infix[i]; ++i) {
        if (isalnum(infix[i])) {
            printf("%c", infix[i]);
        } else if (infix[i] == '(') {
            push(stack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(stack) && stack->array[stack->top] != '(') {
                printf("%c", pop(stack));
            }
            if (!isEmpty(stack) && stack->array[stack->top] != '(') {
                printf("Invalid Expression\n");
                return;
            } else {
                pop(stack); // Pop '(' from the stack
            }
        } else { // Operator encountered
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(stack->array[stack->top])) {
                printf("%c", pop(stack));
            }
            push(stack, infix[i]);   
        }
    }

    // Pop remaining operators from the stack
    while (!isEmpty(stack)) {
        printf("%c", pop(stack));
    }

    free(stack->array);
    free(stack);
}

int main() {
    char infix[100];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    printf("Postfix expression: ");
    infixToPostfix(infix);
    printf("\n");
    return 0;
}

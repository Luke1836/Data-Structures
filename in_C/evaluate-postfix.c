#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

void infixToPostfix(char* infix, char* postfix) {
    struct Stack* stack = createStack(strlen(infix));
    int i, j = 0;

    for (i = 0; infix[i]; ++i) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(stack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(stack) && stack->array[stack->top] != '(') {
                postfix[j++] = pop(stack);
            }
            if (!isEmpty(stack) && stack->array[stack->top] != '(') {
                printf("Invalid Expression\n");
                return;
            } else {
                pop(stack); // Pop '(' from the stack
            } 
        } else { // Operator encountered
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(stack->array[stack->top])) {
                postfix[j++] = pop(stack);
            }
            push(stack, infix[i]);
        }
    }

    // Pop remaining operators from the stack and add to postfix
    while (!isEmpty(stack)) {
        postfix[j++] = pop(stack);
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression

    free(stack->array);
    free(stack);
}

int evaluatePostfix(char* postfix) {
    struct Stack* stack = createStack(strlen(postfix));
    int i, operand1, operand2, result;

    for (i = 0; postfix[i]; ++i) {
        if (isdigit(postfix[i])) {
            push(stack, postfix[i] - '0'); // Convert char to int
        } else {
            operand2 = pop(stack);
            operand1 = pop(stack);

            switch (postfix[i]) {
                case '+':
                    push(stack, operand1 + operand2);
                    break;
                case '-':
                    push(stack, operand1 - operand2);
                    break;
                case '*':
                    push(stack, operand1 * operand2);
                    break;
                case '/':
                    push(stack, operand1 / operand2);
                    break;
            }
        }
    }

    result = pop(stack);
    free(stack->array);
    free(stack);
    return result;
}

int main() {
    char infix[100];
    char postfix[100];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);
    return 0;
}

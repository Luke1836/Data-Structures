#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char infix[100], postfix[100];
int len;
struct Stack {
    int top;
    int capacity;
    char *array;
};

struct Stack *createStack(int n)
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->top = -1;
    s->capacity = n;
    s->array = (char *)malloc(n * sizeof(char));

    return s;
}

int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}

void push(struct Stack *stack, char ch)
{
    stack->array[++stack->top] = ch;
}

char pop(struct Stack *stack)
{
    if(isEmpty(stack))
        return '$';
    else
        return stack->array[stack->top--];
}

int precedence(char ch)
{
    if(ch == '^')
        return 2;
    else if(ch == '/' || ch == '*' || ch == '%')
        return 1;
    else if(ch == '+' || ch == '-')
        return 0;
}

void convertToPostfix()
{
    struct Stack *stack = createStack(len);
    int c = 0, i=0;
    char ch, temp;
    for(int i = 0 ; infix[i] ; i++)
    {
        ch = infix[i];
        if(isalnum(ch))
            postfix[c++] = ch;
        else if(ch == '(')
            push(stack, ch);
        else if(ch == ')')
        {
            while(!isEmpty(stack) && stack->array[stack->top] != ')')
            {
                postfix[c++] = pop(stack);
            }
            if(!isEmpty(stack) && stack->array[stack->top] != ')')
            {
                printf("Invalid Expression!\n");
                exit(1);
            }
            else    
                temp = pop(stack);
        }
        else {
            while(!isEmpty(stack) && precedence(ch) <= precedence(stack->array[stack->top]))
                postfix[c++] = pop(stack);
            push(stack, ch);
        }
    }
    
    while(!isEmpty(stack))
        postfix[c++] = pop(stack);
        
    free(stack->array);
    free(stack);
}

int evaluatePostfix()
{
    struct Stack *s = createStack(len);
    int operand1, operand2, result, temp=1;
    for(int i = 0 ; postfix[i] ; i++)
    {
        if(isdigit(postfix[i]))
            push(s, postfix[i] - '0');
        else{
            operand2 = pop(s);
            operand1 = pop(s);

            switch(postfix[i])
            {
                case '+': push(s, operand1 + operand2);
                          break;
                case '-': push(s, operand1 - operand2);
                          break;
                case '*': push(s, operand1 * operand2);
                          break;
                case '/': push(s, operand1 / operand2);
                          break;
                case '^': for(int i = 1 ; i <= operand2 ; i++)
                            temp *= operand1;
                          push(s, temp);
                          break;
            }
        }
    }
    result = pop(s);
    free(s->array);
    free(s);
    return result;
}

int main(void)
{
    printf("Enter the infix expression:  ");
    scanf("%s", infix);
    fflush(stdin);
    len = strlen(infix);
    convertToPostfix();

    for(int i = 0 ; i < len ; i++)
        printf("%c", infix[i]);
    printf("\n");

    for(int i = 0 ; i < len ; i++)
        printf("%c", postfix[i]);
    printf("\n");
    int result = evaluatePostfix();;
    printf("Value: %d\n", result);
    return 0;
}
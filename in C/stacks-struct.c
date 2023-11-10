#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Stack {
    int top;
    int capacity;
    int *array;
};

struct Stack* createStack(int capacity)
{
    struct Stack *S = malloc(sizeof(struct Stack));
    S->capacity = capacity;
    S->top = -1;
    S->array = malloc(capacity * sizeof(int));
    return S;
}

int isFull(struct Stack *S)
{
    return (S->top == S->capacity-1);
}

int isEmpty(struct Stack *S)
{
    return (S->top == -1);
}

void push(struct Stack *S, int item)
{
    if(!(isFull(S)))
        S->array[++(S->top)] = item;
    else {
        printf("Stack is full!\n");
        return;
    }
}

int pop(struct Stack *S)
{
    if(isEmpty(S))
    {
        printf("The stack is empty\n");
        exit(0);
    }
    else
        return S->array[S->top--];
}

void display(struct Stack *S)
{
    for(int i = 0 ; i < S->capacity-1 ; i++)
        printf("%d\t", S->array[i]);
    printf("\n");
}

int main()
{
    int n, item;
    printf("Enter the size of the stack\n");
    scanf("%d", &n);
    int choice;
    struct Stack *S = createStack(n);
    do{
    printf("\t\t\t\t\t\tSTACK OPERATIONS\n1. Push\n2. Pop\n3. Display\n,4. Exit\nEnter your choice\n");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1: printf("Enter the element to be pushed into the stack\n");
                scanf("%d", &item);
                push(S, item);
                break;
        case 2: printf("THe element popped out is %d\n", pop(S));
                break;
        case 3: display(S);
                break;
        case 4: printf("THe program is terminated!\n");
                break;
        default: printf("Invalid Choice!!!");
    }
    }while(choice != 4);
    return 0;
}
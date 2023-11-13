#include <stdio.h>
#include <stdlib.h>

struct Stacks{
    int data;
    struct Stack *next;
};

void display(struct Stacks *head)
{
    struct Stacks *curr = head;
    if(head == NULL)
    {
        printf("The stack is empty!\n");
        return;
    }
    printf("The Stack elements:  ");
    for(curr = head ; curr != NULL ; curr = curr->next)
        printf("%d -> ", curr->data);
    printf("\n");
}

struct Stacks *insert(struct Stacks *head, int item)
{
    struct Stacks *curr = head, *newNode;
    newNode = (struct Stakcs*)malloc(sizeof(struct Stacks*));
    newNode->data = item;
    newNode->next = NULL;
    if(head == NULL)
    {
        head = newNode;
        head->next = NULL;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
    display(head);
    return head;
}

struct Stacks *pop(struct Stacks *head)
{
    if(head == NULL)
    {
        printf("The stack is empty!\nError: Underflow\n");
        return;
    }
    struct Stack *pred;
    pred = (struct Stakcs*)malloc(sizeof(struct Stacks*));
    pred = head;
    head = head->next;    
    free(pred);
    display(head);
    return head;
}

int main()
{
    struct Stacks *head = NULL;
    int choice, element;
    printf("Stack Operations\n1. Insert an element\n2. Delete an element\n3. Display\n4. Exit\nEnter your choice\n");
    while(1)
    {
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("Enter the element to be inserted:  ");
                    scanf("%d", &element);
                    head = insert(head, element);
                    break;
            case 2: head = pop(head);
                    break;
            case 3: display(head);
                    break;
            case 4: printf("The program execution has been terminated\n");
                    exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 1;
}
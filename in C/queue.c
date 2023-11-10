#include <stdio.h>
#define MAX_SIZE 8

void enqueue();
void dequeue();
void display();
int isFull();
int isEmpty();

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

int main()
{
    int choice;
    do {
        printf("\t\t\t\t\tQueue Operations\n");
        printf("1. Inserting an element into the queue\n");
        printf("2. Deleting an element from the queue\n");
        printf("3. Display the queue\n");
        printf("4. Exit the program\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: enqueue();
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: printf("The program execution has been terminated\n");
                    break;
            default: printf("Invalid choice\n");
        }
    } while(choice != 4);
    return 0;
}

void enqueue()
{
    int ele;
    if(rear == (MAX_SIZE-1))
        printf("The queue is full!\nError: Overflow\n");
    else{
        printf("Enter the element to be inserted into the queue\n");
        scanf("%d", &ele);
        if(front == -1 && rear == -1)
            front = rear = 0;
        queue[rear] = ele;
        rear ++;
        printf("The element, %d has been inserted.\n", ele);
    }
}

void dequeue() 
{
    if(front == -1 || front > rear)
        printf("Error: Underflow\n");
    else
        {
            printf("The element, %d is deleted form the queue\n", queue[front]);
            front ++;
        }
}

void display()
{
    if(front == -1)
        printf("THe queue is empty\n");
    else
    {
        printf("Queue:\n");
        for(int i = front; i <= rear ; i++)
            printf("%d\t", queue[i]);
        printf("\n");
    }   
}

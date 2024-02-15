#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int data;
    struct ListNode *next;
};

struct Queue {
    struct ListNode *front;
    struct ListNode *rear;
};

struct Queue *createQueue()
{
    struct Queue *q = new Queue;
    q->front = q->rear = NULL;
    return q;
}

void enQueue(struct Queue *q, int data)
{
    struct ListNode *newNode = new ListNode;
    newNode->data = data;
    if(q->front == NULL && q->rear == NULL)
    {
        q->front = newNode;
        q->rear = newNode;
    }
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

void deQueue(struct Queue *q)
{
    if(q->front == q->rear)
    {
        q->front = q->rear = NULL;
    }
    else {
        struct ListNode *temp = q->front;
        q->front = q->front->next;
        cout << "The element, " << temp->data << " has been deleted." << endl;
        free(temp);
    }
}

void display(struct Queue *q)
{
    if(q->front == NULL && q->rear == NULL)
    {
        cout << "The Queue is Empty!" << endl;
    }
    else {
        struct ListNode *temp = q->front;
        while(temp != NULL)
        {
            cout << temp->data;
            if(temp->next != NULL)
                cout << " -> ";
            temp = temp->next;
        }
    }
    cout << endl;
}

int main(void)
{
    struct Queue *q = createQueue();
    cout << "Operations Available\n1. Inserting into a queue\n2. Deleteing from a queue\n3. Display the queue\n4. Exit" << endl;
    int choice, data;
    do {
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1: cout << "Enter the element to be inserted" << endl;
                    cin >> data;
                    enQueue(q, data);
                    break;

            case 2: deQueue(q);
                    break;

            case 3: cout << "The Queue: ";
                    display(q);
                    break;

            case 4: exit(0);

            default: cout << "Invalid choice!\nTry Again." << endl;
        } 
    }while(choice != 4);

    return 1;
}
/*
    Program to remove the duplicate elements in a linked list by using the algorithm with the least time complexity.    
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};
struct Node *head = NULL;

struct Node *push(struct Node *head, int data)
{
    struct Node *newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
}

void display()
{
    if(head == NULL)
        cout << "The list is empty" << endl;
    else
    {
        struct Node *temp = head;
        while(temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
}
void removeDuplicates()
{
    struct Node *ptr1, *ptr2, *temp;
    ptr1 = head;
    ptr2 = head->next;
    while(ptr1 != NULL && ptr2 != NULL)
    {
        if(ptr1->data == ptr2->data)
        {
            ptr1->next = ptr2->next;
            temp = ptr2;
            ptr2 = ptr2->next;
            free(ptr2);
        }
        else
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }
}

int main(void)
{
    int n, data;
    cout << "Enter the value of n: ";
    cin >> n;

    for(int i = 0 ; i < n ; i++)
    {
        cout << "Enter the element into the list: ";
        cin >> data;
        head = push(head, data);
    }

    cout << "Original list: ";
    display();
    cout << endl;
    removeDuplicates();
    cout << "List after removing duplicate elements: ";
    display();

    return 0;
}   
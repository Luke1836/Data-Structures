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


void reverseList()
{
    if(head == NULL)
        return;
    struct Node *prev = NULL, *next = NULL, *curr = head;
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

int main(void)
{
    int n;
    cout << "Enter the size of the list " << endl;
    cin >> n;

    cout << "Enter the element" << endl;
    for(int i = 0 ; i < n ; i++)
    {
        int data;
        cin >> data;
        head = push(head, data);
    }
    cout << "Original List: " << endl;
    display();

    reverseList();
    cout << "Reversed List :" << endl;
    display();

    return 1;
}
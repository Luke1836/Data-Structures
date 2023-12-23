#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
};


void push(Node *head, int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void display(Node *head)
{
    if(head == NULL)
        cout << "The list is empty" << endl;
    else
    {
        Node *temp = head;
        while(temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main(void)
{
    Node *head = NULL;
    int n;
    cout << "Enter the size of the list " << endl;
    cin >> n;

    for(int i = 0 ; i < n ; i++)
    {
        int data;
        cout << "Enter the element" << endl;
        cin >> data;
        push(head, data);
    }
    cout << "Original List: " << endl;
    display(head);

}
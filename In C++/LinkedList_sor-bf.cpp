#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
};


Node *push(Node *head, int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
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

Node* mergeList(Node *p1, Node *p2)
{
    Node *result = NULL;
    if(p1 == NULL)
        return p2;
    else if(p2 == NULL)
        return p1;
    
    if(p1->data <= p2->data)
    {
        result = p1;
        result->next = mergeList(p1->next, p2);
    }
    else {
        result = p2;
        result->next = mergeList(p1, p2->next);
    }
    return result;
}

void divideList(Node *head, Node *&p1, Node *&p2)
{
    Node *fast, *slow;
    slow = head;
    fast = head->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    p1 = head;
    p2 = slow->next;
    slow->next = NULL;
}

void mergeSort(Node *&head)
{
    Node *tempHead = head, *p1, *p2;

    if (tempHead == NULL || tempHead->next == NULL)
        return;

    divideList(tempHead, p1, p2);
    mergeSort(p1);
    mergeSort(p2);

    head = mergeList(p1, p2);
}


int main(void)
{
    Node *head = NULL;
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
    display(head);

    mergeSort(head);
    cout << "Sorted array: " << endl;
    display(head);
    return 1;
}
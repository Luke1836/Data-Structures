/*
    Program to insert and delete elements from a circular linked list.
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *last = NULL;

void push(int data)
{
    struct ListNode *newNode = new ListNode;
    struct ListNode *head = last;
    newNode->data = data;
    if(last == NULL)
    {
        last = newNode;
        newNode->next = last;
    }
    else
    {
        /* newNode->next = last->next;
        last->next = newNode; */
        while(head->next != last)
            head = head->next;
        head->next = newNode;
        newNode->next = last;
    }
}

void print()
{
    if(last == NULL)
    {
        cout << "The linked List is empty!" << endl;
        return;
    }
    struct ListNode *temp = last;
    do {
        cout << temp->data << "  ";
        temp = temp->next;
    } while(temp != last);
}

int main(void)
{
    int data, n;
    cout << "Enter the number of node: ";
    cin >> n;

    for(int i = 0 ; i < n ; i++)
    {
        cout << "Enter the element to be pushed: ";
        cin >> data;
        push(data);
    }

    cout << "The Linked list: ";
    print();

    return 0;
}
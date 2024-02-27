#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *head = NULL;

void push(int data)
{
    struct ListNode *newNode = new ListNode, *temp;
    newNode->data = data;
    newNode->next = NULL;
    if(head == NULL)
    {
        head = newNode;
    }
    else 
    {
        temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void print()
{
    struct ListNode *temp = head;
    while(temp != NULL)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << endl;
}

struct ListNode* deleteNode(int key)
{
    struct ListNode *ptr1 = head;
    struct ListNode *ptr2 = head;

    for(int i = 1 ; i <= key ; i++)
    {
        if(ptr2->next == NULL)      //If we are deleting the first element from the list
        {
            if(i == key)
            {
                head = head->next;
            }
            return head;
        }
        ptr2 = ptr2->next;
    }

    while(ptr2->next != NULL)
    {
        ptr2 = ptr2->next;
        ptr1 = ptr1->next;
    }

    ptr1->next = ptr1->next->next;
    return head;
}

int main(void)
{
    int n, data, node;
    cout << "Enter the size of the linked list" << endl;
    cin >> n;

    for(int i = 1 ; i <= n ; i++)
    {
        cout << "Enter the value to be pushed into the linked list: ";
        cin >> data;
        push(data);
    }

    cout << "Enter the node which has to be deleted: ";
    cin >> node;

    cout << "Linked List before deletion: " << endl;
    print();

    cout << endl;
    struct ListNode *delNode = deleteNode(node);

    cout << "Linked List after deletion: " << endl;
    print(); 

    return 1;
}


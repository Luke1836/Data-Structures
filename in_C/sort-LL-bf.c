#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

void display(struct ListNode *head)
{
    struct ListNode *temp = head;
    if(temp == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct ListNode *insert(int ele, struct ListNode *head)
{
    struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->next = NULL;
    newNode->data = ele;
    if(head == NULL)
    {
        head = newNode;
        return head;
    }
    newNode->next = head;
    head = newNode;
    return head;
}

struct ListNode *delete(struct ListNode *head)
{
    struct ListNode *temp = head;
    if(head == NULL)
    {
        printf("The List is empty\nDeletion not possible\n");
        return NULL;
    }
    head = head->next;
    free(temp);
    return head;
}

struct ListNode *sort(struct ListNode *head)
{
    struct ListNode *temp = head, *temp2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    int n = 0;
    while(temp != NULL)
    {
        temp = temp->next;
        n++;
    }
    if(n == 1)
        return head;
    temp = head;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j =0 ; j < n-1-i ; j++)
        {
            if(temp->data > temp->next->data)
            {
                temp2->data = temp->data;
                temp->data = temp->next->data;
                temp->next->data = temp2->data;
            }
            temp = temp->next;
        }
        temp = head;
    }
    return head;
}

int main(void)
{
    struct ListNode *head = NULL;
    int ele, choice;
    printf("Operations\n1. Insertion of a node\n2. Deletion of a node\n3. Sort the list\n4. Display the node\n5.Exit\n");
    while(1)
    {
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: //Inserting a node at the head
                    printf("Enter the element to be inserted\n");
                    scanf("%d", &ele);
                    head = insert(ele, head);
                    printf("THe element has been inserted\n");
                    break;

            case 2: //Deleting an element from the list
                    head = delete(head);
                    printf("Element deletion is completed\n");
                    break;
            
            case 3: //Sorting the linked list
                    head = sort(head);
                    break;
            
            case 4: //Displaying the linked list
                    display(head);
                    break;
            
            case 5: exit(0);

            default: printf("Invalid choice!\nTry Again\n");
        }
    }
    return 0;
}
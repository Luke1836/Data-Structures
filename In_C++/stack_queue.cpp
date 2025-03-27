//Program to implement a stack from queues
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Stack
{
    queue<int> q1, q2;  //In-built queues
    int curr_size;
    public:
        Stack()
        {
            curr_size = 0;
        }

        //Push operation
        void push(int data)
        {
            curr_size ++;
            q2.push(data);

            while(!q1.empty())
            {
                q2.push(q1.front());
                q1.pop();
            }
            queue<int> temp;
            temp = q1;
            q1 = q2;
            q2 = temp;
        }

        void pop()
        {
            if(q1.empty())
                return;
            cout << q1.front() << " is popped out from the stack." << endl;
            q1.pop();
            curr_size--;
        }

        void display()
        {
            queue<int> temp1 = q1, temp2 = q1;
            while(!temp1.empty())
            {
                cout << temp1.front() << " -> ";
                temp1.pop();
            }
            q1 = temp2;
            cout << endl;
        }

        int peek()
        {
            if(q1.empty())
                return -1000;
            return q1.front();
        }

        int size()
        {
            return curr_size;
        }
};

int main(void)
{
    Stack s;
    int choice, data;
    cout << "Operations Available\n1. Push an element into the stack\n2. Pop an element out of the stack\n3. Check the top element\n4. Size of the stack\n5. Exit\n";
    while(1)
    {
        cout << "Enter your choice\n";
        cin >> choice;

        switch(choice)
        {
            case 1: cout << "Enter an element: " << endl;
                    cin >> data;
                    s.push(data);
                    break;
            
            case 2: s.pop();
                    break;
                
            case 3: cout << "The front element of the stack: "  << s.peek() << endl;
                    break;

            case 4: cout << "The size of the stack: " << s.size() << endl;
                    s.display();
                    break;

            case 5: exit(0);

            default: cout << "Invalid Choice\nTry Again!\n";                    
        }
    }
    return 0;
}
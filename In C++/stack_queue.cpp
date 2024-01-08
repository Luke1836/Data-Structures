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

};


int main(void)
{

}
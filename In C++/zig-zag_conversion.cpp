//Program to print a string in a  zig-zag format depending upn the number of rows the user input.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    string str;
    cout << "Enter a string" << endl;
    cin >> str;
    int len = str.length();

    int n, c = 0;
    cout << "Enter the number of rows: " << endl;
    cin >> n;
    string newStr[n];
    bool down;      // Keeps check whether the next movement should be up or down

    if(len == 1)
    {
        cout << str << endl;
        exit(0);
    }

    for(int i = 0 ; i < len ; i++)
    {
        newStr[c] += str[i];
        if(c == n-1)
            down = false;
        else if(c == 0)
            down = true;
        if(down)
            c++;
        else
            c--;        
    }

    cout << "The new String: ";
    for(int i = 0 ; i < n ; i++)
    {
        cout << newStr[i];
    }
    cout << endl;
    return 0;
}
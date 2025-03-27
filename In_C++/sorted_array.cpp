//Program to merge two sorted array
#include <bits/stdc++.h>
#include <iostream>
using namespace std;


int main(void)
{
    int n1,n2,n;
    cout << "Enter the sizes of the two arrays:" << endl;
    cin >> n1;
    cin >> n2;
    n = n1+n2;
    int a1[n1], a2[n2], a3[n];

    cout << "Enter the elements into the first array" << endl;
    for(int i = 0 ; i < n1 ; i++)
        cin >> a1[i];

    cout << "Enter the elements into the second array" << endl;
    for(int i = 0 ; i < n2 ; i++)
        cin >> a2[i];

    int x = 0 , y = 0; 
    for(int i = 0 ; i < n ; i++)
    {
        if(a1[x] < a2[y] && x < n1)
        {
            a3[i] = a1[x];
            x++;
        }
        else {
            a3[i] = a2[y];
            y++;
        }
    }

    cout << "Merged and Sorted array: ";
    for(int i = 0 ; i < n ; i++)
        cout << a3[i] << "  ";
    cout << endl;
    
    return 0;
}
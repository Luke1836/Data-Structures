/*
    Program to sort the colors such that the same colors are adjacent to each other.
    Here we consider the Dutch National Flag. Color Scheme: Red White Blue.
    0 - Red, 1- White, 2 - Blue
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cout << "Enter the size of the array" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the colors: " << endl;
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];
    
}
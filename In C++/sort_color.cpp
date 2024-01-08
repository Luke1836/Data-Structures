/*
    Program to sort the colors such that the same colors are adjacent to each other.
    Using the Dutch National Flag Algorithm
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
    int low = 0, mid = 0, high = n - 1, temp;

    while(mid <= high)
    {
        if(arr[mid] == 0)
        {
            temp = arr[low];
            arr[low] = arr[mid];
            arr[mid] = temp;
            low++;
            mid++;
        }
        else if(arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            temp = arr[high];
            arr[high] = arr[mid];
            arr[mid] = temp;
            high--;
        }
    }

    cout << "Color Scheme: ";
    for(int i = 0 ; i < n ; i++)
        cout << arr[i] << "  ";
    cout << endl;
    return 0;    
}
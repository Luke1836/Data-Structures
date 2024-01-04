//Program to check whether an element is present in a rotated sorted array
#include <bits/stdc++.h>
#include<iostream>
using namespace std;


int main(void)
{
    int n;
    cout << "Enter the size of the array" << endl;
    cin >> n;
    int arr[n];
    int element;

    cout << "Enter the elements" << endl;
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];

    cout << "Enter the element to be searched" << endl;
    cin>>element;

    //Checking whether it is a rotated sorted array
    int lb = 0 ;
    int ub = n-1;
    int mid;

    while(lb <= ub)
    {
        mid = (lb+ub)/2;
        if(arr[mid] == element)
        {
            cout << (mid+1) << endl;
            exit(1);
        }
        else if(arr[lb] > arr[mid])
        {
            if(element > arr[mid] && arr[lb] < element)
                ub = mid - 1;
            else
                lb = mid + 1;

        }
        else 
            lb = mid + 1;
    }

    cout << "-1" << endl;
    return 1;
}
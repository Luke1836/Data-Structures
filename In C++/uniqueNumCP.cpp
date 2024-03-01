#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin>>n;
    int arr[n];
    int arr1[] = {0,1,2,3,4,5,6,7,8};

    for(int i = 0 ; i < n ; i++)
    {
        cin>>arr[i];
    }

    for(int i = 0 ; i < n ; i++)
    {
        int sum = 0;
        int temp = arr[i];
        if(temp <= 9)
        {
            cout << temp << endl;
            continue;
        }
        

    }
    return 1;
}
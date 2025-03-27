//Program to find the subarray with the maximum average value
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cout << "Enter the size of the array" << endl;
    cin >> n;
    int arr[n];

    cout << "Enter the elements into tbe array" << endl;
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];

    int n1; //Store the size of the subarray.
    cout << "Enter the size of the subarray:" << endl;
    cin >> n1;
    double sum = 0.0;
    double max_sum = 0.0;
    int c = 0;

    for(int i = 0 ; i < n ; i++)
    {
        if(i < n1)
        {
            sum += arr[i];
            if(max_sum < sum)
                max_sum = sum;
        }    
        else
        {   sum = sum - arr[c] + arr[i];
            c++;
            if(max_sum < sum)
                max_sum = sum;
        }
    }
    double avg = max_sum / n1;
    cout << "Maximum Average = " << avg << endl;
    return 0;
}
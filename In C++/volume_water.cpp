//Program to find the container which can hold the largest volume of water
#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(void)
{
    int n;
    cout << "Enter the count of the heights for the container" << endl;
    cin >> n;
    int height[n];
    cout << "Enter the heights" << endl;
    for(int i = 0 ; i < n ; i++)
        cin >> height[i];
    int curr_vol = 0;
    int max_vol = INT32_MIN;

    int left = 0, right = n - 1;
    while(left != right)
    {
        curr_vol = min(height[left], height[right]) * (right - left);
        if(curr_vol > max_vol)
            max_vol = curr_vol;
        if(height[left] <= height[right])
            left++;
        else
            right--;
    } 

    cout << "Maximum volume: " << max_vol << endl;
    return 0; 
}
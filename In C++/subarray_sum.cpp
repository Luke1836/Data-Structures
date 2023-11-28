#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, sum;
    int count = 0;
    cout << "Enter the size of the array" << endl;
    cin >> n;
    int arr[n];
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];
    cout << "Enter the sum to be found" << endl;
    cin >> sum;
    unordered_map<int,int> mp;
    int curr_sum;
    int ex_sum;
    for(int i = 0 ; i < n ; i++)
    {
        curr_sum += arr[i];
        if(curr_sum == sum);
            count ++;
        ex_sum = curr_sum - sum;
        if(mp.find(ex_sum) != mp.end())
            count += mp[ex_sum];
        mp[curr_sum]++;
    }
    cout << "Number of subarrays: " << count << endl;
    return 1; 
}
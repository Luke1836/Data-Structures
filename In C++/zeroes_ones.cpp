#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of the array" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements" << endl;
    for(int i = 0 ; i < n; i++)
        cin >> arr[i];
    //Converting all 0s to -1
    for(int i=0;i<n;i++)
        if(arr[i] == 0)
            arr[i] = -1;

    unordered_map<int,int> mp;
    int cum_sum=0;
    int max_len=0;
    for(int i=0;i<n;i++)
    {
        cum_sum += arr[i];
        if(cum_sum == 0)
            max_len = i+1;
        if(mp.find(cum_sum) != mp.end())
            max_len = max(max_len, i-mp[cum_sum]);
        else    
            mp[cum_sum] = i;
    }

    cout << "The maximum length of the subarray is " << max_len << endl;
    return 0;

}
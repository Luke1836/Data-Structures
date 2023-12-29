//Program to find the longest substring with no repeating character
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    string str;
    cout << "Enter a string:" << endl;
    cin >> str;
    int len = str.length();
    int maxLen = 0;
    vector<int> mapp(256,-1); //Stores the last index of the characters
    int l = 0;

    for(int r= 0 ; r < len ; r++)
    {
        l = max(l, mapp[str[r]] + 1);       //is the current element present in the taken string or not
        maxLen = max(maxLen, r-l+1);        //Change the starting index
        mapp[str[r]] = r;                   //Update the map for the current element
    }

    cout << "Maximum length: " << maxLen << endl;
    return 1;

}
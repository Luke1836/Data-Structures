//Program to find the longest common prefix of a string array
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cout << "Enter the number of elements in tha array" << endl;
    cin >> n;
    string name[n];

    for(int i = 0 ; i < n ; i++)
        cin >> name[i];
    
    //We sort the array
    sort(name, name + n);
    string s1 = name[0], s2 = name[n-1];
    string result = "";

    if(s1.length() == 0)
    {
        cout << "" << endl;
        exit(0);
    }

    for(int i = 0 ; i < s1.length() ; i++)
    {
        if(s1[i] == s2[i])
            result += s1[i];
    }

    cout << result << endl;
    return 0;
}

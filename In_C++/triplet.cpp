#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, result;
    cout << "Enter the size of the array " << endl;
    cin >> n;
    int a[n];
    cout << "Enter the elements into the array" << endl;
    for(int i = 0 ; i < n; i++)
        cin >> a[i];
    int flag = 0;
    cout << "Enter the sum " << endl;
    cin >> result;
    sort(a, a+n, greater<int>());
    for(int i = 0 ; i < n; i++)
        cout << a[i] << "  ";
    cout << endl;
    for(int i = 0 ; i < (n-2); i++)
    {
        int j= i+1; int h = n-1;
        while(j<h)
        {
            if((a[i] + a[j] + a[h]) < result )
                j++;
            else if((a[i] + a[j] + a[h]) > result)
                h--;
            else
                {
                    cout << a[i] << "  " << a[j] << "  " << a[h] << endl;
                    flag =1;
                    break;
                }
        }
        if(flag )
            break;
    }
    return 0;
}
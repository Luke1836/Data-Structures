/* 
    This program merges the intervals in a given array or list according to their values and gives a more optimised interval as a result
    This program is useful in finding your free time, i.e., a free interval.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main(void)
{
    int n;
    int f,s;
    cout << "Enter the number of intervals available: ";
    cin >> n;

    vector<vector<int>> interval;
    vector<vector<int>> result;                 //For storing the final result
    cout << "Enter the intervals: " << endl;
    for(int i = 0 ; i < n ; i ++)
    {
        vector<int> temp;                       //For storing an interval
        cin >> f >> s;
        temp.push_back(f);
        temp.push_back(s);
        interval.push_back(temp);
    }

    vector<int> temp2;
    sort(interval.begin(), interval.end());     //Sorting the interval
    temp2 = interval[0];                        //Stores the first interval

    for(auto i : interval)
    {
        if(i[0] <= temp2[1])
        {
            temp2[1] = max(i[1], temp2[1]);
        }
        else {
            result.push_back(temp2);
            temp2 = i;
        }
    }

    result.push_back(temp2);                    //Inserts the final interval

    cout << "The intervals after optimization" << endl;
    for(auto i : result)
    {
        cout << i[0] << "\t" << i[1] << endl;
    }

    return 1;
}
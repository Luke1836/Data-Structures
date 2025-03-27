#include <iostream>
using namespace std;

int main()
{
    int min = INT32_MAX;
    int max_profit = 0;
    int arr[6];
    cout << "Enter the prices of the stock in the 6 days" << endl;
    for(int i = 0 ; i < 6 ; i++)
        cin >> arr[i];
    for(int i = 0 ; i < 6 ; i++)
    {
        if(arr[i] < min)
           min = arr[i];
        max_profit = max(max_profit, (arr[i] - min));
    }
    if(max_profit > 0)
        cout << "Maximum Profit " << max_profit << endl;
    else
        cout << 0 << endl;

    return 1;    
}
#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cout << "Enter the size of the array" <<endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements into the array" << endl;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    int total_sum = 0;
    for(int i=0;i<n;i++)
        total_sum += arr[i];
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        total_sum -= arr[i];
        if(sum == total_sum)
        {
            cout << i << " is the equilibrium position." << endl;
            return 1;
        }
        sum += arr[i];
        
    }

    int current_sum = 0;
    int max_sum = INT_MIN;
    for(int i = 0 ; i< n; i++)
    {
        current_sum += arr[i];
        if(current_sum > max_sum)
            max_sum = current_sum;
        if(current_sum < 0)
            current_sum=0;
    }
    cout << "The maximum sum of a sub array in the given array is " << max_sum << endl;

    cout << "-1. There is no equilibrium position" << endl;
    return 0;

}
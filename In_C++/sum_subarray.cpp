#include <iostream>
using namespace std;

//Maximum sum of a subarray of an array
int main()
{
    int n;
    cout << "Enter the size of the array." << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements" << endl;
    for(int i =0; i <n;i++)
        cin >> arr[i];

    int current_sum = 0;
    int max_sum = INT_MIN; 
    for(int i=0; i < n; i++)
    {
        current_sum += arr[i];
        if(current_sum > max_sum)
            max_sum = current_sum;
        if(current_sum < 0)
            current_sum = 0;
    }

    cout << "The maximum sum of the subarray of the given array is " << max_sum << endl;
    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    int n, element, position;
    position= -1;
    cout << "Enter the size of the array" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements into the array" << endl;
    for(int i = 0; i<n; i++)
        cin >> arr[i];
    int lb = 0;
    int ub = n-1;
    int mid;
    cout << "Enter the element" << endl;
    cin >> element;
    while(lb <= ub)
    {
        mid = (lb+ub)/2;
        if(arr[mid] == element)
            {
                ub=mid-1;
                position = mid;
            }
        else if(arr[mid] > element)
            ub = mid-1;
        else
            lb = mid + 1;
    }
    cout << "The position is " << (position+1) << endl;
    return 0;

}
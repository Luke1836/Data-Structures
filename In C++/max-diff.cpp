#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of the array." << endl;
    cin >>n;
    int arr[n];
    cout << "Enter the element into the array " << endl;
    for (int i=0;i<n;i++)
        cin >> arr[i];
    int max_diff = arr[1] - arr[0];
    int min_element = arr[0];

    for(int i=1;i<n;i++)
    {
        if(arr[i] < min_element)
            min_element = arr[i];
    }
    for(int i = 0 ; i<n ; i++)
        if(arr[i] - min_element > max_diff)
            max_diff = arr[i] - min_element;

    cout << "The minimum element is " << min_element << " and the maximum difference is " << max_diff << endl;
    return 0;
}
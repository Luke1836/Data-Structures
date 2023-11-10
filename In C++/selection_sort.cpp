#include <iostream>
using namespace std;

int main()
{
    cout << "Enter the size of the array"<< endl;
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter the elements into thw array: ";
    for(int i = 0; i< n ; i++)
        cin >> arr[i];
    
    cout << endl;
    cout << "The array after sorting: ";

    for(int i = 0 ; i < (n-1) ; i++)
    {
        int small = arr[i];
        int pos = i;

        for(int j = i+1 ; j < n ; j++)
            if(arr[j] < small)
            {
                small = arr[j];
                pos = j;
            }

        arr[pos] = arr[i];
        arr[i] = small;
    }

    for(int i = 0 ; i < n ; i++)
        cout << arr[i] << "  ";
    cout << endl;
}
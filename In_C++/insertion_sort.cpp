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

    for(int i = 1 ; i < n ; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    
    cout << endl;
    cout << "The array after sorting: ";
    for(int i = 0 ; i < n ; i++)
        cout << arr[i] << "  ";
    cout << endl;

}

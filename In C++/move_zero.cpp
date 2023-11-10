#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of the array" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements into the array" << endl;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    
    int j = 0;
    int temp;
    for(int i=0;i<n;i++)
    {
        if(arr[i] != 0)
            {arr[j] = arr[i];
             j++;
            }
    }
    for(int i = j; i<n;i++)
        arr[i] =0;
    for(int i=0;i<n;i++)
        cout << arr[i] << "  ";
    cout << endl;
    return 0;
}
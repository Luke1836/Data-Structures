#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of the array" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements" << endl;
    for(int i = 0 ; i < n; i++)
        cin >> arr[i];
    

    for(int i = 0 ; i < n; i+=2)
    {
        if(i>0 && (arr[i] < arr[i-1]))
        {
            int temp;
            temp = arr[i];
            arr[i] = arr[i-1];
            arr[i-1] = temp; 
        }

    
        if(i < (n-1) && (arr[i] < arr[i+1]))
        {
            int temp;
            temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }

    cout << "The wave array: ";
    for(int i=0;i<n;i++)
        cout << arr[i] << "  ";
    cout<<endl;
    return 0;
}
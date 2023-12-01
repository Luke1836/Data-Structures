#include <iostream>
using namespace std;

int main() 
{
    int n;
    cout << "Enter the size of the array" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements into the array" << endl;
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];
    
    int maj_index = 0;
    int count = 1;
    for(int i=1;i<n;i++)
    {
        if(arr[i] == arr[maj_index])
            count++;
        else
            count--;
        if(count==0)
        {
            maj_index=i;
            count = 1;
        }
    }

    count = 0;
    for(int i = 0 ; i < n ; i++)
        if(arr[i] == arr[maj_index])
            count++;
    
    if(count > (n/2))
        cout << "The majority element is " << arr[maj_index] << endl;
    else
        cout << "There is no majority element." << endl;
}
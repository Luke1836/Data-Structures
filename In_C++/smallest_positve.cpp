#include <iostream>
using namespace std;

int main()
{
    int size;
    int c=0;
    cout << "Enter the size of the array" << endl;
    cin >> size;
    int arr[size];
    cout<<"Enter the elements" << endl;
    for(int i=0;i<size;i++)
        cin>>arr[i];
    int newArr[size];
    for(int i=0;i<size;i++)
        if(arr[i]>0)
            newArr[c++]= arr[i];

    for(int i =0;i<c;i++)
    {
        newArr[abs(newArr[i])-1] = -1*newArr[abs(newArr[i])-1]; 
    }
    for(int i = 0 ;i<c;i++)
        if(newArr[i]>0)
            cout<<"The smallest missing element is " << (i+1)<<endl;
    
    return 0;


}
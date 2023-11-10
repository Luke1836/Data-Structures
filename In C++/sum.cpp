#include <iostream>
using namespace std;

int main()
{
    int n, target;
    int j;
    cout << "Enter the size of the array: " << endl;
    cin >> n;
    int a[n];
    int newArr[] ={0,0};
    cout << "Enter the elements into the array:" << endl;
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    cout << "Enter the target" << endl;
    cin >> target;


    for(int i = 0 ; i < (n-1) ; i++)
    {
        

    }
    if((newArr[0] == 0) && (newArr[1] == 0))
        return 1;
    cout << "Output: " << newArr[0] << "  " << newArr[1] << endl;
    return 0;
}
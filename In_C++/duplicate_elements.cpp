#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of the array" << endl;
    cin >> n;
    int arr[n];
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];
    int h,t;
    h = arr[0];
    t = arr[0];
    do {
        t = arr[t];
        h = arr[arr[h]];
    } while(h != t);
    int p1 = arr[0];
    int p2 = h;

    while(p1 != p2)
    {
        p1 = arr[p1];
        p2 = arr[p2];
    }

    if(p1 == p2)
        cout << "The element repeating is " << p1 << endl;
    else 
        cout << "-1" << endl;
    return 1;
}
#include <iostream>
using namespace std;


int main()
{
    cout << "Enter the sizes of two arrays" << endl;
    int n1, n2;
    cin >> n1;
    cin >> n2;
    int arr1[n1], arr2[n2];

    cout << "Enter the elements into the first array" << endl;
    for(int i = 0 ;  i < n1 ; i++)
        cin >> arr1[i];
    cout << "Enter the elements into the second array" << endl;
    for(int i = 0 ;  i < n2 ; i++)
        cin >> arr2[i];
    
    int nt = n1+n2;
    int arr3[nt];
    int arr4[nt];
    int arr5[n1];
    int n = 0;

    cout << "THe Union of them is: ";
    for(int i = 0 ; i < n1 ; i++)
        arr3[n++] = arr1[i];
    
    for(int i = 0 ; i < n2 ; i ++)
        {
            int c = 0;
            for(int j = 0 ; j < n1 ; j++)
                if(arr2[i] == arr1[j])
                    {
                        c++;
                        break;
                    }
            if(c == 0)
                arr3[n++] = arr2[i];
        }

    for(int i = 0 ; i < n ; i++)
        cout << arr3[i] << "   ";
    cout << endl; 

    int max, min;
    cout << "The intersection of two sets is: ";
    if(n1 > n2)
        {max = n1;
         min = n2;
        }
    else 
        {max = n2;
         min = n1;
        }
    for(int i = 0 ; i < max ; i++)
    {
        if(i < min)
            {if(arr1[i] == arr2[i])

                {
                    cout << arr1[i] << "  ";
                }
            }
    }
    cout << endl;
    for(int i = 0 ; i < n1 ; i ++)
        {
            int c= 0;
            for(int j = 0 ; j < n2 ; j++)
                if(arr1[i] != arr2[j])
                    c++;
            if(c == n2)
             cout << arr1[i] << "  "; 
        }
}
#include <iostream>
using namespace std;


int main(void)
{
    cout << "Enter the number" << endl;
    int num;
    cin >> num;
    int copy = num;
    int num_zeros = 0;
    while(num != 0)
    {
        num /= 5;
        num_zeros += num;
    }

    cout << "The number of trailing zeroes in the factorial of " << copy << " is " << num_zeros << endl;
    return 0;

}
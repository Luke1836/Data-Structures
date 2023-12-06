#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int j = 0; j < t; j++) {
        int arr[42];
        for (int i = 0; i < 42; i++) {
            cin >> arr[i];
        }

        int count = 0;
        for (int i = 0; i < 42; i++) {
            if (arr[i] != (i + 1)) {
                int swapIndex;
                for (int k = i + 1; k < 42; k++) {
                    if (arr[k] == (i + 1)) {
                        swapIndex = k;
                        break;
                    }
                }

                if (swapIndex == -1) {
                    count += 2;
                } else {
                    count++;
                    int temp = arr[i];
                    arr[i] = arr[swapIndex];
                    arr[swapIndex] = temp;
                }
            }
        }

        if (count > 1) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    return 0;
}
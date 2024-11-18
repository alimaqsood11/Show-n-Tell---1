#include <iostream>
using namespace std;

void printPairs(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "(" << arr[i] << ", " << arr[j] << ") ";
        }
        cout << endl;
    }
}

int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printPairs(arr, n);
    return 0;
}

//This example shows a quadratic time complexity, where a nested loop results in time increasing quadratically with input size.
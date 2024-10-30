#include <iostream>
using namespace std;

int getFirstElement(int arr[], int n) {
    return arr[0];
}

int main() {
    int arr[] = {5, 10, 15, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "First element: " << getFirstElement(arr, n) << endl;
    return 0;
}

//This code example demonstrates constant time complexity, where the function completes in the same amount of time regardless of the input size.

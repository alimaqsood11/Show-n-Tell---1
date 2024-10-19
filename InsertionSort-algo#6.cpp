#include <iostream>
using namespace std;

int main() {
    const int size = 6;
    int arr[size] = { 34, 7, 23, 32, 5, 62 };
    for (int j = 1; j < size; j++) {
        int i = 0, m = arr[j];
        while (arr[j] > arr[i]) i++;
        for (int k = j; k > i; k--) arr[k] = arr[k - 1];
        arr[i] = m;
    }
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    return 0;
}
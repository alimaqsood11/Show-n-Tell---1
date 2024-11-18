#include <iostream>
using namespace std;

int main() {
    const int n = 6;
    int arr[n] = { 34, 7, 23, 32, 5, 62 };
    for (int i = 0; i < n - 1; i++) for (int j = i + 1; j < n; j++) if (arr[i] < arr[j]) swap(arr[i], arr[j]);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
    //Time complexity: O(n²)
}
#include <iostream>
using namespace std;

// Function to perform binary search (O(log n))
int binarySearch(int arr[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    
    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1)
        cout << "Element not present in array." << endl;
    else
        cout << "Element is present at index " << result << endl;

    return 0;
}

//Binary search operates in logarithmic time complexity by dividing the search space in half with each iteration.

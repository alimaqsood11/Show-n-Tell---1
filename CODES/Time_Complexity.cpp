
#include <iostream>
using namespace std;
int linearSearch(int arr[], int n, int x); // (Time: O(n), Space: O(1))
int binarySearch(int arr[], int n, int x); // (Time: O(log n), Space: O(1))
int recursiveBinarySearch(int arr[], int left, int right, int x); // (Time: O(log n), Space: O(log n))
// You can adjust the array however you like
int main()
{
    int choice = 0;
    cout << "Enter 1 for linear search " << endl<< "Enter 2 for binary search " << endl << "Enter 3 for Recursive binary call :";
    cin >> choice;
    if (choice == 1) {
        int arr[] = { 2, 4, 6, 8, 10 };
        int n = sizeof(arr) / sizeof(arr[0]);
        int x = 6;
        int result = linearSearch(arr, n, x);
        (result != -1) ? cout << "Element found at index " << result : cout << "Element not found";
    }
    else if (choice == 2) {
        int arr[] = { 2, 4, 6, 8, 10 };
        int n = sizeof(arr) / sizeof(arr[0]);
        int x = 6;
        int result = binarySearch(arr, n, x);
        (result != -1) ? cout << "Element found at index " << result : cout << "Element not found";
    }
    else if (choice == 3) {
        int arr[] = { 2, 4, 6, 8, 10 };
        int n = sizeof(arr) / sizeof(arr[0]);
        int x = 6;
        int result = recursiveBinarySearch(arr, 0, n - 1, x);
        (result != -1) ? cout << "Element found at index " << result : cout << "Element not found";
        return 0;
    }
    return 0;
}

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i; // Return index if element is found
        }
    }
    return -1; // Return -1 if element is not found
}

int binarySearch(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the element is at the mid
        if (arr[mid] == x)
            return mid;

        // If x is greater, ignore the left half
        if (arr[mid] < x)
            left = mid + 1;
        // If x is smaller, ignore the right half
        else
            right = mid - 1;
    }
    return -1; // Element not found
}
int recursiveBinarySearch(int arr[], int left, int right, int x) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if element is at mid
        if (arr[mid] == x)
            return mid;

        // If x is smaller, search in the left half
        if (arr[mid] > x)
            return recursiveBinarySearch(arr, left, mid - 1, x);

        // If x is larger, search in the right half
        return recursiveBinarySearch(arr, mid + 1, right, x);
    }
    return -1; // Element not found
}
#include <iostream>
using namespace std;
int main() 
{
    int x;
    const int size = 10;
    int arr[size] = {12,67,54,84,53,23,39,99,78,67};//you can change the array.
    cout << "Enter the element to search for: ";
    cin >> x;
    int index;
    for (index = 0; index < size && arr[index] != x; index++);// for locating index.

    if (index < size) cout << "Element found at index: " << index << endl;
    else cout << "Element not found in the array." << endl;
    return 0;
  //  Time Complexity : O(n) (linear search through the array).
  //  Space Complexity : O(1) (constant space).
}

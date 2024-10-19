#include<iostream>
using namespace std;
int main()
{
    const int size=10;
    int arr[size] = {};
    for (int i = 0; i < size; i++) cin >> arr[i];//input
    int max = arr[0];
    for (int i = 1; i < size; ++i)
    {
        if (arr[i] > max) max = arr[i];
    }
    cout << "The maximum element is: " << max << endl;//output
    return 0;
 //The program reads each element of the array once.
 //Each element is compared against the current assigned maximum value to variable.
 //The number of operations grows linearly with the number of elements .
 //Time Complexity: O(size) which is O(n) in general).
 //Space Complexity: O(1) bcz only a few variables like max and n are used.
}
#include <iostream>
using namespace std;

int main() {
    int x;
    const int n = 10;
    int arr[n] = {10,45,98,76,54,56,76,56,34,56};
    cout << "enter the number you want to find : ";
    cin >> x;
    int i = 0, j = n - 1;
    while (i <= j) {
        int m = (i + j) / 2;
        if (arr[m] == x) {
            cout << "number found at index : " << m;;
            return 0;
        }
        else if (arr[m] < x) i = m + 1;
        else j = m - 1;
    }
    cout << "index not found !";
    return 0;
    //best case : Time complexity : O(1).(The element is found at the middle in the first comparison)
    //worst case : time complexity : O(log(n)) (The element is not found, or it is located at one of the extreme ends of the array.)
    //average case : Time complexity:  O(logn). (the element could be found any where in the array.)
    //you can change the size and elements of given array/assumed array.
}

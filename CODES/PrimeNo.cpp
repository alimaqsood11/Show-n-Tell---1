#include <iostream>
#include <conio.h>
using namespace std;

bool isprime(int n);              // Function to check if a number is prime
void goldb(int n, int &i, int &j); // Function to find the Goldbach pair

int main()
{
    int n, i = 0, j = 0;
    cout << "Enter an even number greater than 2: ";
    cin >> n;

    // --------------------------------------------------------------
    // Input Validation (Time Complexity: O(1))
    // --------------------------------------------------------------
    // Ensure that the number entered is valid for Goldbach's conjecture.
    // This is a simple check with constant time complexity.
    if (n <= 2 || n % 2 != 0)
    {
        cout << "Please enter an even number greater than 2." << endl;
        return 0;
    }

    // --------------------------------------------------------------
    // Goldbach Pair Search (Time Complexity: O(n * sqrt(n)))
    // --------------------------------------------------------------
    // The function goldb() searches for two prime numbers that add up to n.
    // This loop iterates from 2 to n/2, and for each number i, it checks
    // if both i and n-i are prime (isprime() function).
    goldb(n, i, j); // Call the function to find the pair of primes

    // Display the result
    if (i != 0 && j != 0)
    {
        cout << "Goldbach pair: " << i << " + " << j << " = " << n << endl;
    }
    else
    {
        cout << "No Goldbach pair found." << endl;
    }

    _getch();
    return 0;
}

//--------------------------------------------
// Function to check if a number is prime
bool isprime(int n)
{
    // --------------------------------------------------------------
    // Prime Check (Time Complexity: O(sqrt(n)))
    // --------------------------------------------------------------
    // The function checks if a number n is divisible by any number from 2 to n-1.
    // However, the most efficient way to check primality is to stop at sqrt(n)
    // because a larger factor of n must be a multiple of a smaller factor.
    if (n <= 1)
    {
        return false;
    }
    for (int i = 2; i * i <= n; i++) // Check divisibility from 2 to sqrt(n)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true; // Return true if no divisors were found
}

//--------------------------------------------
// Function to find the Goldbach pair
void goldb(int n, int &i, int &j)
{
    // --------------------------------------------------------------
    // Searching for Goldbach Pair (Time Complexity: O(n * sqrt(n)))
    // --------------------------------------------------------------
    // This loop runs from 2 to n/2. For each number i, it calculates j = n - i,
    // and checks if both i and j are prime using the isprime() function.
    // Since the prime check is O(sqrt(n)) and isprime() is called for each i,
    // the overall complexity for this function is O(n * sqrt(n)).
    for (i = 2; i <= n / 2; i++) // Iterate from 2 to n/2
    {
        j = n - i; // j is the complement of i such that i + j = n

        if (isprime(i) && isprime(j)) // Check if both i and j are prime
        {
            return; // Stop as soon as we find the pair
        }
    }

    // If no pair is found, reset i and j to indicate no solution
    i = 0;
    j = 0;
}
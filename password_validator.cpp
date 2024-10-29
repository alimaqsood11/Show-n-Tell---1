#include <iostream>

bool isValidPassword(const char password[]) {
    // --------------------------------------------------------------
    // Calculate length manually (Time Complexity: O(n))
    // --------------------------------------------------------------
    // This while loop runs until it finds the null terminator ('\0').
    // For a password of length n, it performs n iterations.
    int length = 0;
    while (password[length] != '\0') {
        ++length;
    }

    // --------------------------------------------------------------
    // Check minimum length constraint (Time Complexity: O(1))
    // --------------------------------------------------------------
    // Checking whether the length is less than 8 is a constant time operation.
    if (length < 8) {
        return false;
    }

    // Initialize flags for checking different character types
    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false, hasSpace = false;
    char specialChars[] = "!@#$%^&*()-_+=<>?";

    // --------------------------------------------------------------
    // Iterate through the password and check character types (Time Complexity: O(n))
    // --------------------------------------------------------------
    // This loop runs once for each character in the password (n iterations).
    // Inside this loop, we perform constant time checks (O(1)) for each character.
    for (int i = 0; i < length; ++i) {
        char ch = password[i];

        if (ch == ' ') {
            hasSpace = true;  // Check if a space is entered (O(1))
        } else if (ch >= 'A' && ch <= 'Z') {
            hasUpper = true;  // Check if it's an uppercase letter (O(1))
        } else if (ch >= 'a' && ch <= 'z') {
            hasLower = true;  // Check if it's a lowercase letter (O(1))
        } else if (ch >= '0' && ch <= '9') {
            hasDigit = true;  // Check if it's a digit (O(1))
        } else {
            // --------------------------------------------------------------
            // Check if the character is a special character (Time Complexity: O(k))
            // --------------------------------------------------------------
            // Checking each special character requires a nested loop.
            // The inner loop runs over the specialChars array, which has k elements.
            // In this case, k is a small constant (~16), so the time complexity is O(k).
            for (int j = 0; specialChars[j] != '\0'; ++j) {
                if (ch == specialChars[j]) {
                    hasSpecial = true;
                    break;
                }
            }
        }
    }

    // --------------------------------------------------------------
    // Return false if space is found or if any condition is not met (Time Complexity: O(1))
    // --------------------------------------------------------------
    // Returning the result based on the conditions is done in constant time (O(1)).
    return !hasSpace && hasUpper && hasLower && hasDigit && hasSpecial;
}

int main() {
    char password[100];
    
    // Get user input for password (Time Complexity: O(n))
    // The time complexity depends on the length of the password entered.
    std::cout << "Enter a password: ";
    std::cin >> password;

    // Checking the validity of the password
    if (isValidPassword(password)) {
        std::cout << "Password is valid." << std::endl;
    } else {
        std::cout << "Password is invalid. It must be at least 8 characters long, "
                     "include upper case letters, lower case letters, digits, special characters, and no spaces."
                  << std::endl;
    }

    return 0;
}
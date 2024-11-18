#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

void generateTicketNumber(int length) {
    if (length == 0) return;
    cout << rand() % 10;
    generateTicketNumber(length - 1);
}

void generateAlphanumericTicket(int length) {
    if (length == 0) return;
    int choice = rand() % 2;
    if (choice == 0) {
        cout << char(rand() % 10 + '0');
    } else {
        cout << char(rand() % 26 + 'A');
    }
    generateAlphanumericTicket(length - 1);
}

bool checkTicketContains7(string ticket, int index) {
    if (index < 0) return false;
    if (ticket[index] == '7') return true;
    return checkTicketContains7(ticket, index - 1);
}

void checkTicketForWinning(int ticketLength) {
    string ticket;
    for (int i = 0; i < ticketLength; i++) {
        ticket += to_string(rand() % 10);
    }
    cout << "Generated Ticket Number: " << ticket << endl;
    if (checkTicketContains7(ticket, ticket.length() - 1)) {
        cout << "Yes, the ticket contains 7!" << endl;
    } else {
        cout << "No, the ticket does not contain 7." << endl;
    }
}

void menu(int choice) {
    if (choice == 1) {
        int length = (rand() % 2) + 5;
        cout << "Generated Ticket Number of length " << length << ": ";
        generateTicketNumber(length);
        cout << endl;
    } else if (choice == 2) {
        int length = rand() % 3 + 5;
        cout << "Generated Alphanumeric Ticket of length " << length << ": ";
        generateAlphanumericTicket(length);
        cout << endl;
    } else if (choice == 3) {
        int length = rand() % 2 + 5;
        cout << "Checking ticket for number '7': ";
        checkTicketForWinning(length);
    } else if (choice == 4) {
        cout << "Exiting the program." << endl;
        return;
    } else {
        cout << "Invalid choice, please try again." << endl;
    }
    int newChoice;
    cout << "\nEnter your choice again (1-3 for operations, 4 to exit): ";
    cin >> newChoice;
    menu(newChoice);
}

int main() {
    srand(time(0));
    cout << "Welcome to the Random Ticket Generator!" << endl;
    cout << "1. Generate Random Ticket Number (5 or 6 digits)" << endl;
    cout << "2. Generate Alphanumeric Ticket (letters and digits)" << endl;
    cout << "3. Check Ticket for Winning Number '7'" << endl;
    cout << "4. Exit" << endl;
    int choice;
    cout << "Enter your choice (1-4): ";
    cin >> choice;
    menu(choice);
    return 0;
}

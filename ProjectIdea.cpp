#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <conio.h>
#include <thread>
#include <chrono>
#include <windows.h> // For SetConsoleTextAttribute and HANDLE
using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void setColor(int color) {
    SetConsoleTextAttribute(hConsole, color);
}

void resetColor() {
    SetConsoleTextAttribute(hConsole, 7); // Default console color
}

void recursiveGenerateTicketNumber(string& ticket, int length) {
    if (_kbhit()) return;
    for (int i = 0; i < length; i++) {
        ticket[i] = '0' + rand() % 10;
    }
    cout << "\rGenerating Ticket: ";
    for (char ch : ticket) {
        if (ch == '7') setColor(14); // Yellow for 7
        else if (ch == '1') setColor(9); // Blue for 1
        else if (ch == '0') setColor(12); // Red for 0
        else setColor(10); // Green for others
        cout << ch;
        resetColor();
    }
    cout.flush();
    this_thread::sleep_for(chrono::milliseconds(100));
    recursiveGenerateTicketNumber(ticket, length);
}

void recursiveGenerateAlphanumeric(string& ticket, int length) {
    if (_kbhit()) return;
    for (int i = 0; i < length; i++) {
        if (rand() % 2 == 0) {
            ticket[i] = '0' + rand() % 10;
        }
        else {
            ticket[i] = 'A' + rand() % 26;
        }
    }
    cout << "\rGenerating Alphanumeric Ticket: ";
    for (char ch : ticket) {
        if (isdigit(ch)) setColor(10); // Green for digits
        else setColor(13); // Magenta for letters
        cout << ch;
        resetColor();
    }
    cout.flush();
    this_thread::sleep_for(chrono::milliseconds(100));
    recursiveGenerateAlphanumeric(ticket, length);
}

void recursiveGenerateShapes(string& shapes, int length, const char symbols[]) {
    if (_kbhit()) return;
    for (int i = 0; i < length; i++) {
        shapes[i] = symbols[rand() % 3];
    }
    cout << "\rGenerating Shapes: ";
    for (char ch : shapes) {
        if (ch == '$') setColor(14); // Yellow for $
        else if (ch == '@') setColor(12); // Red for @
        else if (ch == '#') setColor(10); // Green for #
        cout << ch;
        resetColor();
    }
    cout.flush();
    this_thread::sleep_for(chrono::milliseconds(100));
    recursiveGenerateShapes(shapes, length, symbols);
}

void recursiveCheckTicketForWinning(string& ticket, int length) {
    if (_kbhit()) return;
    for (int i = 0; i < length; i++) {
        ticket[i] = '0' + rand() % 10;
    }
    cout << "\rGenerating Ticket: ";
    for (char ch : ticket) {
        if (ch == '7') setColor(14); // Yellow for 7
        else if (ch == '1') setColor(9); // Blue for 1
        else if (ch == '0') setColor(12); // Red for 0
        else setColor(10); // Green for others
        cout << ch;
        resetColor();
    }
    cout.flush();
    this_thread::sleep_for(chrono::milliseconds(100));
    recursiveCheckTicketForWinning(ticket, length);
}

void generateTicketNumberWithAnimation(int length) {
    string ticket(length, '_');
    cout << "Generating Ticket: ";
    recursiveGenerateTicketNumber(ticket, length);
    _getch();
    cout << "\nFinal Ticket: " << ticket << endl;
}

void generateAlphanumericWithAnimation(int length) {
    string ticket(length, '_');
    cout << "Generating Alphanumeric Ticket: ";
    recursiveGenerateAlphanumeric(ticket, length);
    _getch();
    cout << "\nFinal Alphanumeric Ticket: " << ticket << endl;
}

void generateShapesWithAnimation() {
    const char shapesArray[] = { '@', '#', '$' };
    string shapes(3, '_');
    cout << "Generating Shapes: ";
    recursiveGenerateShapes(shapes, 3, shapesArray);
    _getch();
    cout << "\nFinal Shapes: " << shapes << endl;

    if (shapes[0] == shapes[1] && shapes[1] == shapes[2]) {
        cout << "Bingo! All shapes match: ";
        for (char ch : shapes) {
            if (ch == '$') setColor(14);
            else if (ch == '@') setColor(12);
            else if (ch == '#') setColor(10);
            cout << ch;
            resetColor();
        }
        cout << endl;
    }
    else {
        cout << "No Bingo! Shapes do not match." << endl;
    }
}

void checkTicketForWinningWithAnimation(int length) {
    string ticket(length, '_');
    cout << "Generating Ticket: ";
    recursiveCheckTicketForWinning(ticket, length);
    _getch();
    cout << "\nFinal Ticket: " << ticket << endl;

    if (ticket.find('7') != string::npos) {
        cout << "Yes, the ticket contains 7!" << endl;
    }
    else {
        cout << "No, the ticket does not contain 7." << endl;
    }
}

void menu(int choice) {
    if (choice == 1) {
        int length = (rand() % 2) + 5;
        generateTicketNumberWithAnimation(length);
    }
    else if (choice == 2) {
        int length = rand() % 3 + 5;
        generateAlphanumericWithAnimation(length);
    }
    else if (choice == 3) {
        int length = rand() % 2 + 5;
        checkTicketForWinningWithAnimation(length);
    }
    else if (choice == 4) {
        generateShapesWithAnimation();
    }
    else if (choice == 5) {
        cout << "Exiting the program." << endl;
        return;
    }
    else {
        cout << "Invalid choice, please try again." << endl;
    }
    int newChoice;
    cout << "\nEnter your choice again (1-5 for operations): ";
    cin >> newChoice;
    menu(newChoice);
}

int main() {
    srand(time(0));
    cout << "Welcome to the Random Ticket Generator!" << endl;
    cout << "1. Generate Random Ticket Number (5 or 6 digits)" << endl;
    cout << "2. Generate Alphanumeric Ticket (letters and digits)" << endl;
    cout << "3. Check Ticket for Winning Number '7'" << endl;
    cout << "4. Generate Shapes and Check for Bingo" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice (1-5): ";
    int choice;
    cin >> choice;
    menu(choice);
    return 0;
}

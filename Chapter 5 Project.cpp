
#include <iostream>

using namespace std;

int main() {
    // Variable for the maximum number of characters in the rows
    const int MAX_ROWS = 10;

    // --- PATTERN A ---
    // This loop handles the increasing pattern
    cout << "Pattern A" << endl;
    for (int i = 1; i <= MAX_ROWS; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "+";
        }
        cout << endl;
    }

    // Space between patterns
    cout << endl;

    // --- PATTERN B ---
    // This loop handles the decreasing pattern
    cout << "Pattern B" << endl;
    for (int i = MAX_ROWS; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout << "+";
        }
        cout << endl;
    }

    return 0;
}
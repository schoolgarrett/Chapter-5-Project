#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string fileName, townName;
    ifstream inputFile;
    int year = 1900;
    long population;

    // Get basic info
    cout << "Town name: ";
    getline(cin, townName);
    cout << "File name: ";
    cin >> fileName;

    // Open and check file
    inputFile.open(fileName);
    if (!inputFile) {
        cout << "Error opening file." << endl;
        return 1;
    }

    cout << "\n" << townName << " Population Growth\n";
    cout << "(each * = 1,000 people)\n--------------------\n";

    // Read population and plot stars
    while (inputFile >> population) {
        cout << year << " ";

        // Loop to print 1 star per 1,000 people
        for (int i = 0; i < (population / 1000); i++) {
            cout << "*";
        }

        cout << endl;
        year += 20; // Move to next interval
    }

    inputFile.close();
    return 0;
}
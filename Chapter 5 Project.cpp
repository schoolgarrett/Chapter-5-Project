#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // Variable declarations
    int startingOrganisms;
    double dailyIncreaseRate;
    int numDays;

    // 1. Input Validation
    // Starting population must be >= 2
    cout << "Enter the starting number of organisms (minimum of 2): ";
    while (!(cin >> startingOrganisms) || startingOrganisms < 2) {
        cout << "Invalid input. Enter an integer 2 or greater: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    // Daily increase must be > 0 (real number/double)
    cout << "Enter average daily population increase (percentage, 5 for 5%): ";
    while (!(cin >> dailyIncreaseRate) || dailyIncreaseRate <= 0) {
        cout << "Invalid input. Enter a positive number for the growth rate: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    // Number of days must be >= 1
    cout << "Enter the number of days they will multiply: ";
    while (!(cin >> numDays) || numDays < 1) {
        cout << "Invalid input. Enter 1 or more days: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    // 2. Population Calculation & Output
    double currentPopulation = startingOrganisms;

    // Convert percentage to decimal (e.g., 5% becomes 0.05)
    double growthFactor = dailyIncreaseRate / 100.0;

    cout << "\nTable of Population Growth" << endl;
    cout << "--------------------------" << endl;
    cout << left << setw(10) << "Day" << "Population" << endl;

    for (int day = 1; day <= numDays; day++) {
        // Requirement: Display the size for each day
        cout << left << setw(10) << day << fixed << setprecision(2) << currentPopulation << endl;

        // Calculate next day's growth
        // Formula: New Pop = Current Pop + (Current Pop * Growth Rate)
        currentPopulation += (currentPopulation * growthFactor);
    }

    return 0;
}
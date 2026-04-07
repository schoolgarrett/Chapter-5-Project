#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;

int main() {
    // 1. Seed the random number generator with current time
    unsigned seed = time(0);
    srand(seed);

    // 2. Generate a random number between 1 and 100
    // Formula: (rand() % (maxValue - minValue + 1)) + minValue
    int randomNumber = (rand() % 100) + 1;
    int userGuess = 0;
    int attempts = 0;

    cout << "I have generated a random number between 1 and 100." << endl;
    cout << "Can you guess what it is?" << endl;

    // 3. Loop until the user guesses the correct number
    while (userGuess != randomNumber) {
        cout << "\nEnter your guess: ";

        // 4. Input Validation: Ensure the user enters an integer
        if (!(cin >> userGuess)) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear(); // Clear error flags
            cin.ignore(1000, '\n'); // Discard bad input
            continue;
        }

        attempts++;

        // 5. Provide feedback
        if (userGuess > randomNumber) {
            cout << "Too high, try again." << endl;
        }
        else if (userGuess < randomNumber) {
            cout << "Too low, try again." << endl;
        }
        else {
            cout << "Correct! You guessed it in " << attempts << " attempts." << endl;
        }
    }

    return 0;
}
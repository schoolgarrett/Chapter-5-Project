#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Variables to track data
    string currentName;
    string firstStudent;
    string lastStudent;
    int studentCount = 0;

    // Open the input file
    ifstream inputFile;
    inputFile.open("LineUp.txt");

    // 1. Input Validation: Verify the file opened successfully
    if (!inputFile) {
        cout << "Error: Could not open the file LineUp.txt" << endl;
        return 1; // Exit with error code
    }

    // 2. Read data until End-of-File (EOF)
    while (inputFile >> currentName) {
        // If this is the first student read, initialize first and last
        if (studentCount == 0) {
            firstStudent = currentName;
            lastStudent = currentName;
        }
        else {
            // 3. Apply string comparisons for alphabetical order
            if (currentName < firstStudent) {
                firstStudent = currentName;
            }
            if (currentName > lastStudent) {
                lastStudent = currentName;
            }
        }
        studentCount++;
    }

    // Close the file
    inputFile.close();

    // 4. Output the results
    if (studentCount > 0) {
        cout << "Number of students in the class: " << studentCount << endl;
        cout << "Student at the front of the line: " << firstStudent << endl;
        cout << "Student at the end of the line: " << lastStudent << endl;
    }
    else {
        cout << "The file was empty. No students found." << endl;
    }

    return 0;
}
// Included all the necesary libraries
#include <iostream>
using namespace std;
#include <iomanip>
#include <string>
#include <array>
#include <limits>
#include <cctype>

namespace logWorkout{

const int MAX_WORKOUTS = 15;      // Making sure that the users can only log up to 15 workouts, this can be changed!
string activities[MAX_WORKOUTS];  // Using Arrays to store the inputs
double durations[MAX_WORKOUTS];   // Using Arrays to store the inputs
int workoutCount = 0;             // Setting the initial count to 0
// Function to log and display workouts
void logWorkout(string activities[], double durations[], int &workoutCount) {
    char choice = 'y'; // Used for user input

    while (choice == 'y' || choice == 'Y') { // Loop only when user inputs 'y' or 'Y'
        if (workoutCount >= MAX_WORKOUTS) { // Initial checker - Checking if it's full or not
            cout << setfill(' ') << setw(10) << "" << "Workout log is full, We cannot add more workouts." << endl;
            return;
        }

        cout << setfill(' ') << setw(10) << "" << setfill('=') << setw(40) << "" << endl;
        cout << setfill(' ') << setw(10) << "" << "Please Enter your workout activity: " << endl;
        cout << setfill(' ') << setw(10) << "" << setfill('-') << setw(5) << "" << "> ";

        // Clears leftover input only once when first workout is being logged to prevent skipping issues
        if (workoutCount == 0) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // had a white space bug fixed
        }
        getline(cin, activities[workoutCount]); // Store activity name


        cout << setfill(' ') << setw(10) << "" << setfill('=') << setw(40) << "" << endl;
        cout << setfill(' ') << setw(10) << "" << "Please Enter your duration in minutes: " << endl;
        cout << setfill(' ') << setw(10) << "" << setfill('-') << setw(5) << "" << "> ";
        cin >> durations[workoutCount];

        // Basic input validation using numeric_limits
        while (cin.fail() || durations[workoutCount] <= 0) { // or
            cout << setfill(' ') << setw(10) << "" << "Invalid input! Enter a valid number of minutes: ";

            cin.clear();  // Clearing the error again
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cin >> durations[workoutCount]; // Ask again for a valid input
        }

        workoutCount++; // Increase workout count

        cout << setfill(' ') << setw(10) << "" << setfill('=') << setw(40) << "" << endl;
        cout << setfill(' ') << setw(10) << "" << "Workout Logged Successfully!" << endl;
        cout << setfill(' ') << setw(10) << "" << "Your Total Workouts Logged So Far Are : " << endl;
        cout << setfill(' ') << setw(10) << "" << setfill('-') << setw(5) << "" << "> " << workoutCount << endl;


        cout << setfill(' ') << setw(10) << "" << setfill('=') << setw(40) << "" << endl;
        // Again Loops and asks if the users want to log again
        cout << setfill(' ') << setw(10) << "" << "Would you like to log another workout? (y/n): ";
        cin >> choice;

        // Clears any extra input + avoids issues on the next loop iteration
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        //checks for N for no
        if (choice == 'n' || choice == 'N') {
            cout << setfill(' ') << setw(10) << "" << "Exiting The workout!" << endl;
            cout << setfill(' ') << setw(10) << "" << setfill('=') << setw(40) << "" << endl;
            break; //  Correctly exits the loop
        }
    }
}
}

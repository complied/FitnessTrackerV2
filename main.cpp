//
//  main.cpp
//  Fitness Tracker
//
//  Created by Subigya Parajuli on 2/10/25.
//

#include <iostream>
using namespace std;
#include <iomanip>

#include "include/DisplayMenu.h"
#include "include/calorieChecker.h"
#include "include/workoutReccomendation.h"
#include "include/workoutLogger.h"
#include "include/workoutAssign.h"
#include "include/fileManager.h"


// ****** Updated All these, Included every hpp function in main ******

int main(int argc, const char * argv[]) {
    int choice;

    while (true) { // Loop until the user chooses to exit
        displayMenu::displayMenu(); // Function calling in main - now works!

        cout << "Enter your choice: ";
        cin >> choice;

        // Input validation
        if (cin.fail()) {
            cin.clear();  // Clears the error flag
            cin.ignore();  // Clears input buffer
            cout << "Invalid input! Please Re-Enter a number: ";
            cin >> choice;
        }

        switch (choice) {
            case 1:
                calorieChecker::calorieChecker();
                break;
            case 2:
                workoutReccomendation::workoutReccomendation(); // Workout Recommender function here now
                break;
            case 3:
                logWorkout::logWorkout(logWorkout::activities, logWorkout::durations, logWorkout::workoutCount);
                break;
            case 4:
                workoutManager::assignWorkoutToDay(logWorkout::activities, logWorkout::durations, logWorkout::workoutCount); // connected both - logged workout to workout manager
                break;
            case 5:
                cout << "Exiting program. Thank you for using the fitness tracker!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 5." << endl;
        }


        cout << setfill(' ') << setw(10) << ""<< "Please Press Enter to return to the main menu.";
        cin.ignore(); // Clears input buffer
        cin.get(); // Waits for Enter key - Waits for any characters with white spaces for examples enter or return!
    }

    return 0;
}
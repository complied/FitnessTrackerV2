
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
namespace calorieChecker{
void calorieChecker() {
    double weight, time, burnedCalories = 0;
    string workOuts;

    while (true) { //put this in a while loop to let it loop untill done!
        cout << setfill(' ') << setw(10) << "" << setfill('=') << setw(40) << "" << endl;
        cout << setfill(' ') << setw(10) << "" << "[Running] - [Swimming] - [Biking]" << endl;
        cout << setfill(' ') << setw(10) << "" << "Choose one of the following: ";
        cin >> workOuts;

        if (workOuts == "Running" || workOuts == "Swimming" || workOuts == "Biking") {
            break; // Exit loop if input is valid if not it will be in there till its right
        }

        cout << setfill(' ') << setw(10) << "" << setfill('=') << setw(40) << "" << endl;
        cout << setfill(' ') << setw(10) << "" << "Wrong input: Enter what's written on the screen & try again." << endl;
    }

    while (true) {
        cout << setfill(' ') << setw(10) << "" << "Please Enter Your Weight In Kgs: " << endl;
        cout << setfill(' ') << setw(10) << "" << setfill('-') << setw(5) << "" << "> ";
        cin >> weight; // takes in weight input

        if (cin.fail() || weight <= 0) {
            cin.clear(); // Clears the error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input - just how learned in class
            cout << setfill(' ') << setw(10) << "" << "Invalid input. Please enter a valid weight." << endl;
        } else {
            break;
        }
    }

    while (true) {
        cout << setfill(' ') << setw(10) << "" << setfill('=') << setw(40) << "" << endl;
        cout << setfill(' ') << setw(10) << "" << "Please Enter Your Duration In Minutes: " << endl;
        cout << setfill(' ') << setw(10) << "" << setfill('-') << setw(5) << "" << "> ";
        cin >> time;

        if (cin.fail() || time <= 0) { // another error checker!
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input - just how learned in class
            cout << setfill(' ') << setw(10) << "" << "Invalid input. Please enter a valid duration." << endl;
        } else {
            break;
        }
    }

    if (workOuts == "Running") {
        burnedCalories = weight * 0.0175 * 9.8 * time; // MET value for running (~6 mph) = 9.8
    } else if (workOuts == "Swimming") {
        burnedCalories = weight * 0.0175 * 7.0 * time; // MET value for swimming (moderate effort) = 7.0
    } else if (workOuts == "Biking") {
        burnedCalories = weight * 0.0175 * 8.0 * time; // MET value for biking (~12-14 mph) = 8.0
    }

    cout << fixed << setprecision(2); // Format decimals
    cout << setfill(' ') << setw(10) << "" << "Your estimated calories burned are: " << endl;
    cout << setfill(' ') << setw(10) << "" << setfill('-') << setw(5) << "" << "> " << burnedCalories << " KCal" << endl; // Resends how much it is in decimals!
}
}

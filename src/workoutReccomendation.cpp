// Included all the necesary libraries
#include <iostream>
using namespace std;
#include <iomanip>
#include <string>

namespace workoutReccomendation{
void workoutReccomendation() {
    string workoutChoice;

    // Display welcome message
    cout << setfill(' ') << setw(10) << "" << setfill('=') << setw(40) << "" << endl;
    cout << setfill(' ') << setw(10) << "" << "Welcome to the Workout Recommender" << endl;
    cout << setfill(' ') << setw(10) << "" << setfill('=') << setw(40) << "" << endl;

    // Loop until valid input is provided
    while (true) {  // Keeps running until a valid choice is entered
        cout << setfill(' ') << setw(10) << "" << "[Beginner] - [Moderate] - [Intermediate]" << endl;
        cout << setfill(' ') << setw(10) << "" << "Choose one of the following: ";
        cin >> workoutChoice;
        cout << endl; // Extra line for spacing

        // Check if the input is valid
        if (workoutChoice == "Beginner" || workoutChoice == "Moderate" || workoutChoice == "Intermediate") {
            break;  // use of break to exit the loop if the input is valid
        } else {
            // If invalid input, display error message and prompt again
            cout << setfill(' ') << setw(10) << "" << setfill('=') << setw(40) << "" << endl;
            cout << setfill(' ') << setw(10) << "" << "Invalid choice! Please enter a valid difficulty level." << endl;
            cout << setfill(' ') << setw(10) << "" << setfill('=') << setw(40) << "" << endl;
        }
    }

    // Workout plan heading
    cout << endl; // Extra line for spacing
    cout << setfill(' ') << setw(10) << "" << "Your Workout Plan:" << endl;
    cout << setfill(' ') << setw(10) << "" << setfill('=') << setw(40) << "" << endl;

    if (workoutChoice == "Beginner") {
        string beginnerWorkouts[3][5] = {
            {"Push Day", "Push-ups", "Bench Press", "Tricep Dips", "Overhead Press"},
            {"Pull Day", "Pull-ups", "Lat Pulldown", "Bicep Curls", "Face Pulls"},
            {"Cardio Day", "Running", "Jump Rope", "Cycling", "Burpees"}
        };
        // Used 2 Nested for-loops to locate the data in the 2D arrays
        for (int i = 0; i < 3; i++) {
            cout << setfill(' ') << setw(10) << "" << "Day " << (i + 1) << " - " << beginnerWorkouts[i][0] << ":" << endl;
            for (int j = 1; j < 5; j++) {
                cout << setfill(' ') << setw(15) << "" << "- " << beginnerWorkouts[i][j] << endl;
            }
            cout << setfill(' ') << setw(10) << "" << setfill('=') << setw(40) << "" << endl;
        }
    }
    else if (workoutChoice == "Moderate") {
        string moderateWorkouts[4][5] = {
            {"Push Day", "Incline Bench Press", "Dumbbell Shoulder Press", "Tricep Dips", "Lateral Raises"},
            {"Pull Day", "Deadlifts", "Chin-ups", "Bicep Curls", "Seated Row"},
            {"Leg Day", "Squats", "Lunges", "Leg Press", "Calf Raises"},
            {"Cardio Day", "Treadmill Sprints", "Jump Rope", "Rowing Machine", "HIIT Workouts"}
        };
        // Used 2 Nested for-loops to locate the data in the 2D arrays
        for (int i = 0; i < 4; i++) {
            cout << setfill(' ') << setw(10) << "" << "Day " << (i + 1) << " - " << moderateWorkouts[i][0] << ":" << endl;
            for (int j = 1; j < 5; j++) {
                cout << setfill(' ') << setw(15) << "" << "- " << moderateWorkouts[i][j] << endl;
            }
            cout << setfill(' ') << setw(10) << "" << setfill('=') << setw(40) << "" << endl;
        }
    }
    else if (workoutChoice == "Intermediate") {
        string intermediateWorkouts[6][5] = {
            {"Push Day", "Barbell Bench Press", "Dips", "Overhead Press", "Incline Dumbbell Press"},
            {"Pull Day", "Weighted Pull-ups", "Bent-over Rows", "Barbell Curls", "Face Pulls"},
            {"Leg Day", "Front Squats", "Romanian Deadlifts", "Leg Curls", "Standing Calf Raises"},
            {"Cardio Day", "Sprint Intervals", "Cycling", "Box Jumps", "Battle Ropes"},
            {"Upper Body", "Dumbbell Shoulder Press", "Chest Flys", "Lat Pulldown", "Triceps Extensions"},
            {"Full Body", "Power Cleans", "Deadlifts", "Kettlebell Swings", "Farmer's Walk"}
        };
        // Used 2 Nested for-loops to locate the data in the 2D arrays
        for (int i = 0; i < 6; i++) {
            cout << setfill(' ') << setw(10) << "" << "Day " << (i + 1) << " - " << intermediateWorkouts[i][0] << ":" << endl;
            for (int j = 1; j < 5; j++) {
                cout << setfill(' ') << setw(15) << "" << "- " << intermediateWorkouts[i][j] << endl;
            }
            cout << setfill(' ') << setw(10) << "" << setfill('=') << setw(40) << "" << endl;
        }
    }
}
}

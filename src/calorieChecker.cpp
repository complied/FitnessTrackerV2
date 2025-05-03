// ===== calorieChecker.cpp =====
#include "../include/calorieChecker.h"
#include <fstream>
#include <limits>

using namespace std;

namespace calorieChecker {

// Convert string input into WorkoutType enum
WorkoutType parseWorkout(const string& s) {
    if (s == "Running") return WorkoutType::Running;
    if (s == "Swimming") return WorkoutType::Swimming;
    return WorkoutType::Biking;
}

void calorieCalculator() {
    string workOuts;
    double weight, duration, burned;

    // Workout selection loop
    while (true) {
        cout << setfill(' ') << setw(10) << "" << setfill('=') << setw(40) << "" << endl;
        cout << setfill(' ') << setw(10) << "" << "[Running] - [Swimming] - [Biking]" << endl;
        cout << setfill(' ') << setw(10) << "" << "Choose one of the following: ";
        cin >> workOuts;
        if (workOuts == "Running" || workOuts == "Swimming" || workOuts == "Biking") break;
        cout << setfill(' ') << setw(10) << "" << "Invalid choice, try again." << endl;
    }

    // Weight input
    cout << setfill(' ') << setw(10) << "" << "Please Enter Your Weight In Kgs: ";
    cin >> weight;

    // Duration input
    cout << setfill(' ') << setw(10) << "" << "Please Enter Your Duration In Minutes: ";
    cin >> duration;

    // Calculate calories
    WorkoutType wt = parseWorkout(workOuts);
    if (wt == WorkoutType::Running)
        burned = weight * 0.0175 * 9.8 * duration;
    else if (wt == WorkoutType::Swimming)
        burned = weight * 0.0175 * 7.0 * duration;
    else
        burned = weight * 0.0175 * 8.0 * duration;

    cout << fixed << setprecision(2);
    cout << setfill(' ') << setw(10) << "" << "Your estimated calories burned are: " << endl;
    cout << setfill(' ') << setw(10) << "" << setfill('-') << setw(5) << ""
         << "> " << burned << " KCal" << endl;
}

void emergencyTracker() {
    // Creating unique pointer session - stored now in the heap
    unique_ptr<CalorieSession> session = make_unique<CalorieSession>();
    string workOuts;

    // Workout selection for emergency
    while (true) {
        cout << "Enter emergency workout [Running] [Swimming] [Biking]: ";
        cin >> workOuts;
        if (workOuts == "Running" || workOuts == "Swimming" || workOuts == "Biking") break;
        cout << "Invalid input. Try again." << endl;
    }
    session->type = parseWorkout(workOuts);

    // Weight and duration input\ n    cout << "Weight (kg): "; cin >> session->weight;
    cout << "Duration (min): "; cin >> session->duration;

    // Compute calories
    if (session->type == WorkoutType::Running)
        session->calories = session->weight * 0.0175 * 9.8 * session->duration;
    else if (session->type == WorkoutType::Swimming)
        session->calories = session->weight * 0.0175 * 7.0 * session->duration;
    else
        session->calories = session->weight * 0.0175 * 8.0 * session->duration;

    // Save to CSV file in specified directory
    ofstream outFile("/Users/subigyaparajuli/Desktop/FitnessTrackerV2/data/emergency_session.csv", ios::app);
    if (outFile.is_open()) {
        // Append a line: WorkoutType,Weight,Duration,Calories
        outFile << workOuts << ","
                << session->weight << ","
                << session->duration << ","
                << session->calories << endl;
        outFile.close();
        cout << "Emergency session recorded to CSV." << endl;
    } else {
        cerr << "Failed to open CSV for emergency tracker." << endl;
    }
    // unique_ptr frees memory automatically
}

} // namespace calorieChecker

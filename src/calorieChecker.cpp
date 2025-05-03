// ===== calorieChecker.cpp =====
#include "../include/calorieChecker.h"
#include <fstream>
#include <limits>

using namespace std;

namespace calorieChecker {

    // Converts a workout name string into the corresponding enum value.
    WorkoutType parseWorkout(const string& s) {
        if (s == "Running") {
            return WorkoutType::Running; //maping straight to enum
        }
        else if (s == "Swimming") {
            return WorkoutType::Swimming;
        }
        else {
            return WorkoutType::Biking; // last options so default
        }
    }


    void calorieCalculator() {
        //storing this at 0 for safety and clarity
        string workOuts;         // holds user input for workout type
        double weight = 0.0;     // holds user input for weight
        double duration = 0.0;   // holds user input for duration
        double burned = 0.0;     // will store computed calories

        // selecting the workouts now
        while (true) {
            // display menu header
            cout << setfill(' ') << setw(10) << "" << setfill('=') << setw(40) << "" << endl;
            cout << setfill(' ') << setw(10) << "" << "[Running] - [Swimming] - [Biking]" << endl;
            cout << setfill(' ') << setw(10) << "" << "Choose one of the following: ";
            cin >> workOuts;  // read into string

            // validate input
            if (workOuts == "Running" || workOuts == "Swimming" || workOuts == "Biking") {
                break;  // valid selection, exit loop
            }
            // invalid selection, prompt again
            cout << setfill(' ') << setw(10) << "" << "Invalid choice, try again." << endl;
        }

        // User entering weight
        cout << setfill(' ') << setw(10) << "" << "Please Enter Your Weight In Kgs: " << endl;
        cout << setfill(' ') << setw(10) << "" << setfill('-') << setw(5) << "" << "> ";
        cin >> weight;  // weight in kg

        // Entering duration
        cout << setfill(' ') << setw(10) << "" << setfill('=') << setw(40) << "" << endl;
        cout << setfill(' ') << setw(10) << "" << "Please Enter Your Duration In Minutes: " << endl;
        cout << setfill(' ') << setw(10) << "" << setfill('-') << setw(5) << "" << "> ";
        cin >> duration;  // duration in minutes

        // Total burnt calories
        WorkoutType wt = parseWorkout(workOuts); // changing from STRING to ENUM
        if (wt == WorkoutType::Running) {
            burned = weight * 0.0175 * 9.8 * duration;
        }
        else if (wt == WorkoutType::Swimming) {
            burned = weight * 0.0175 * 7.0 * duration;
        }
        else {
            burned = weight * 0.0175 * 8.0 * duration;
        }
        cout << fixed << setprecision(2);
        cout << setfill(' ') << setw(10) << "" << "Your estimated calories burned are: " << endl;
        cout << setfill(' ') << setw(10) << "" << setfill('-') << setw(5) << "" << "> "
             << burned << " KCal" << endl;
    }

    void emergencyTracker() {
        // Create a CalorieSession instance on the heap
        // unique_ptr<CalorieSession> manages the memory automatically
        unique_ptr<CalorieSession> session = make_unique<CalorieSession>();

        string workOuts;  // to capture workout type input
        while (true) {
            cout << setfill(' ') << setw(10) << "" << setfill('=') << setw(40) << "" << endl;
            cout << setfill(' ') << setw(10) << "" << "[Running] - [Swimming] - [Biking]" << endl;
            cout << setfill(' ') << setw(10) << "" << "Choose emergency workout: ";
            cin >> workOuts;
            if (workOuts == "Running" || workOuts == "Swimming" || workOuts == "Biking") {
                break;
            }
            cout << setfill(' ') << setw(10) << "" << "Invalid input. Try again." << endl;
        }
        // Map string to enum, store in struct
        session->type = parseWorkout(workOuts);
        cout << setfill(' ') << setw(10) << "" << "Enter weight (kg): " << endl;
        cin >> session->weight;  // store directly into struct

        // -- Enter duration --
        cout << setfill(' ') << setw(10) << "" << "Enter duration (min): " << endl;
        cin >> session->duration;  // store directly into struct

        // -- Compute calories burned and store
        if (session->type == WorkoutType::Running) {
            session->calories = session->weight * 0.0175 * 9.8 * session->duration;
        }
        else if (session->type == WorkoutType::Swimming) {
            session->calories = session->weight * 0.0175 * 7.0 * session->duration;
        }
        else {
            session->calories = session->weight * 0.0175 * 8.0 * session->duration;
        }

        // printing into csv file now~
        const string path = "/Users/subigyaparajuli/Desktop/FitnessTrackerV2/data/emergency_session.csv";
        ofstream outFile(path, ios::app);  // open in append mode
        if (outFile.is_open()) {
            // Write CSV line: workout,weight,duration,calories
            outFile << workOuts << ","
                    << session->weight << ","
                    << session->duration << ","
                    << session->calories << endl;
            outFile.close();  // close file to flush data

            // calories burnt now
            cout << "Your total calories that have been burnt is : " << session->calories << endl;
            cout << "Now it is being stored in your file." << endl;
        }
        else {
            // Error handling if file fails to open
            cerr << "Error: Could not open " << path << " for writing." << endl;
        }
    }

}
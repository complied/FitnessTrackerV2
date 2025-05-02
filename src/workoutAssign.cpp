#include "../include/workoutAssign.h"  // allows the function
#include "../include/workoutLogger.h" // Including workoutLogger to access activities and durations

using namespace std;

namespace workoutManager {
    map<string, vector<shared_ptr<workout>>> workoutManager;

    workout::workout(const string &t, double d) : type(t), duration(d) {} // workout constructor


    void assignWorkoutToDay(string activities[], double durations[], int workoutCount) {
        for (int i = 0; i < workoutCount; i++) { // switching through each workout
            string day;

            // assigning workout activity to selected day
            cout << "Please Enter a day you want to assign the workout: [ " << activities[i] << " ] ";
            cin >> day;

            if (workoutManager[day].size() >= 5) { // limiting maximym to 5
                cout << "Day is full! Cannot assign more workouts to " << day << ".\n";
                continue;
            }

            // Creating a shared_ptr pointing to a new Workout object
            shared_ptr<workout> workoutPtr = make_shared<workout>(activities[i], durations[i]);

            // Add the workout pointer to the selected day's vector inside the map
            workoutManager[day].push_back(workoutPtr);

            cout << "Perfect! Your Workout [" << activities[i] << "] has been assigned to: " << day << "\n";
        }
    }
}

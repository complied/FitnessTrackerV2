#ifndef Utils_workoutLogger
#define Utils_workoutLogger

// Included all the necesary libraries
#include <iostream>
using namespace std;
#include <iomanip>
#include <string>

namespace logWorkout {
    const int MAX_WORKOUTS = 100;

    // Declare variables globally so they can be used in main.cpp
    extern string activities[MAX_WORKOUTS];
    extern double durations[MAX_WORKOUTS];
    extern int workoutCount;

    void logWorkout(string activities[], double durations[], int &workoutCount); // defined function in the hpp file!

# endif
}


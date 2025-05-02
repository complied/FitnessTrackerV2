
Fitness Tracker
# Overview
A simple C++ program that helps users log workouts, get workout recommendations, and calculate calories burned based on activity type.

#Features
- Log workout type and duration
- Get basic workout recommendations
- Calculate total calories burned
- Workout Assign


V - 0.1 -
+ Added a Display function with error handling.
+ Proper display with <iomanip> library implementation!

v - 0.2 -
=======
Fitness Tracker

# Overview
A simple C++ program that helps users log workouts, get workout recommendations, and calculate calories burned based on activity type.

#Features
- Log workout type and duration
- Get basic workout recommendations
- Calculate total calories burned
- Workout Assign


V - 0.1 -
+ Added a Display function with error handling.
+ Proper display with <iomanip> library implementation!

v - 0.2 -
+ New Feature: Added a Calorie Calculator, which allows users to estimate calories burned based on their weight, workout type, and duration.
+ Supports three workout types: Running, Swimming, and Biking.
+ Implements error handling for invalid inputs, prompting users to enter the correct workout name.
+ Uses MET (Metabolic Equivalent of Task) values for accurate calorie estimation:
    + Running (~6 mph): MET = 9.8
    + Swimming (moderate effort): MET = 7.0
    + Biking (~12-14 mph): MET = 8.0
+ Outputs calculated calories burned in a formatted, user-friendly manner with two decimal precision.
+ Updated Menu function! - Better flexiblity

<<<<<<< HEAD
v - 0.3 -

+ Implemented New Features for #CalorieChecker!
    + Used cin.fail(), cin.ignore(), and numeric_limits to improve input validation.
    + Ensures only valid inputs are accepted, preventing bugs and crashes.

+Removed Fitness.cpp/Fitness.hpp files
+ Organized all functions into their own .cpp and .hpp files for better structure and maintainability.

+ New Function Added! #WorkoutRecommendation
    + Recommends workouts based on different fitness levels:
        + Beginner- 3-day workout plan
        + Moderate - 4-day workout plan
        + Intermediate - 6-day workout plan

v - 0.4 --

+ Created A New Function! #WorkoutLogger! Uses the parameeters of string[], int[]
+ Added a configuration for how many workouts you can log - In this case 15
    + Uses arrays to store workout activities and durations
+ Using If to check y for yes more & n for no more logging

+ Security
    + Added std::numeric_limits<streamsize>::max() to clear input buffer and prevent skipping issues.
        + Usuage of cin.ignore and getline to avoid invalid duration inputs

+ Updated Code for Workout Reccomendation!
    + Now the security bug got fixed
    + Added a while-loop to ensure valid input selection before proceeding.
      Users can no longer enter invalid options like and proceed.
      +C learer formatting for invalid input messages.
    + Prevents accidental exits due to incorrect input.


+ Updated Main!
    + Now added a loop in main where, Now It wont end Untill user presses Enter or return - Bascially White Space
    + Now Theres Another Switch statement added - 4 To exit!
    + Loops and Loops now!
    + added extra Cin command cin.get(); & cin.fail();

v - 0.5.5 --

+ Implemented AssignWorkoutDay function
    + - Connects with workoutLogger by accessing the existing global arrays (activities, durations, and workoutCount).
        - Passes these arrays as parameters into assignWorkoutToDay()
        - Goes through the workouts, creates shared pointers, and assigns them to days inside a map<string, vector<shared_ptr<workout>>>.
        - Added 5 times a week limitations for reccomendations.

    + White space bug fixed
        - Missing break statement in main , Case 4 fixed.
        - cin.ignore() being called before every getline() caused white space/enter issue - > next workout being skipped.
        - Replaced it with cin.ignore() every time workoutcount == 0.
          =======
          v - 0.3 -

+ Implemented New Features for #CalorieChecker!
    + Used cin.fail(), cin.ignore(), and numeric_limits to improve input validation.
    + Ensures only valid inputs are accepted, preventing bugs and crashes.

+Removed Fitness.cpp/Fitness.hpp files
+ Organized all functions into their own .cpp and .hpp files for better structure and maintainability.

+ New Function Added! #WorkoutRecommendation
    + Recommends workouts based on different fitness levels:
        + Beginner- 3-day workout plan
        + Moderate - 4-day workout plan
        + Intermediate - 6-day workout plan

v - 0.4 --

+ Created A New Function! #WorkoutLogger! Uses the parameeters of string[], int[]
+ Added a configuration for how many workouts you can log - In this case 15
    + Uses arrays to store workout activities and durations
+ Using If to check y for yes more & n for no more logging

+ Security
    + Added std::numeric_limits<streamsize>::max() to clear input buffer and prevent skipping issues.
        + Usuage of cin.ignore and getline to avoid invalid duration inputs

+ Updated Code for Workout Reccomendation!
    + Now the security bug got fixed
    + Added a while-loop to ensure valid input selection before proceeding.
      Users can no longer enter invalid options like and proceed.
      +C learer formatting for invalid input messages.
    + Prevents accidental exits due to incorrect input.


+ Updated Main!
    + Now added a loop in main where, Now It wont end Untill user presses Enter or return - Bascially White Space
    + Now Theres Another Switch statement added - 4 To exit!
    + Loops and Loops now!
    + added extra Cin command cin.get(); & cin.fail();

v - 0.5.5 --

+ Implemented AssignWorkoutDay function
    + - Connects with workoutLogger by accessing the existing global arrays (activities, durations, and workoutCount).
        - Passes these arrays as parameters into assignWorkoutToDay()
        - Goes through the workouts, creates shared pointers, and assigns them to days inside a map<string, vector<shared_ptr<workout>>>.
        - Added 5 times a week limitations for reccomendations.

    + White space bug fixed
        - Missing break statement in main , Case 4 fixed.
        - cin.ignore() being called before every getline() caused white space/enter issue - > next workout being skipped.
        - Replaced it with cin.ignore() every time workoutcount == 0.

- Refrance - [Before](https://imgur.com/a/4EvP0jg) VS [After](https://imgur.com/a/vvwaKLP)


v - 0.6 

+ Updated WorkoutReccomendation 
  + Swapped the old module - 2d arrays -> vectors
  + Created new menu inside the existing option - 3 levels selectable - 1) Beginner, 2) Moderate, 3) Intermedeiate
    + Customized User input + New workouts 
    + Used Map for better selection .add feature
  
+ Udpated WorkoutReccomendation Bug 
  + Security 
    + User validation - Checks only for user input 
    + Used Enum to keep things more secure and manager 
    + Used Struc to store map which includes a vector 

===================================================

Youtube Video here ------ > https://www.youtube.com/watch?v=IcDLU2BOBRM
Link to V1 - https://github.com/complied/FitnessTracker
===================================================


Some Sources Used to complete this project!
=======
Some Sources Used to complete this project!

https://www.geeksforgeeks.org/
https://stackoverflow.com/
https://cplusplus.com/doc/
https://devdocs.io/cpp/
https://www.instituteoflifestylemedicine.org/wp-content/uploads/2015/04/METValues.pdf [PDF link]

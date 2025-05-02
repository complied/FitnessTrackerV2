cmake_minimum_required(VERSION 3.31)
project(FitnessTrackerV2)

set(CMAKE_CXX_STANDARD 20)

add_executable(FitnessTrackerV2 main.cpp
        include/calorieChecker.h
        include/DisplayMenu.h
        include/fileManager.h
        include/workoutAssign.h
        include/workoutLogger.h
        include/workoutReccomendation.h
        src/calorieChecker.cpp
        src/DisplayMenu.cpp
        src/fileManager.cpp
        src/workoutAssign.cpp
        src/workoutLogger.cpp
        src/workoutReccomendation.cpp
)

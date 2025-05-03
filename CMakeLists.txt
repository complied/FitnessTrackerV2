cmake_minimum_required(VERSION 3.31)
project(FitnessTrackerV2)

set(CMAKE_CXX_STANDARD 20)

# Main executable
add_executable(FitnessTrackerV2
        main.cpp
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

# Enable testing
enable_testing()

# Add GoogleTest submodule (make sure the folder exists!)
add_subdirectory(extern/googletest)

# Test executable
add_executable(FitnessTrackerTests
        test/test_name_validation.cpp
        src/calorieChecker.cpp
        src/workoutLogger.cpp
        src/workoutAssign.cpp
        src/fileManager.cpp
)

# Link GoogleTest and pthread
target_link_libraries(FitnessTrackerTests
        gtest
        gtest_main
        pthread
)

# Discover tests
include(GoogleTest)
gtest_discover_tests(FitnessTrackerTests)

// test_main.cpp
#include <gtest/gtest.h>
#include "../include/calorieChecker.h"
#include "../include/workoutLogger.h"

using namespace calorieChecker;
using namespace logWorkout;

// --------- TESTS FOR parseWorkout() ---------
TEST(CalorieCheckerTests, ParseWorkout_ValidInputs) {
    EXPECT_EQ(parseWorkout("Running"), WorkoutType::Running);
    EXPECT_EQ(parseWorkout("Swimming"), WorkoutType::Swimming);
    EXPECT_EQ(parseWorkout("Biking"), WorkoutType::Biking);
}

TEST(CalorieCheckerTests, ParseWorkout_InvalidDefaultsToBiking) {
    EXPECT_EQ(parseWorkout("Walking"), WorkoutType::Biking);
    EXPECT_EQ(parseWorkout("Yoga"), WorkoutType::Biking);
    EXPECT_EQ(parseWorkout(""), WorkoutType::Biking);
}

// --------- TESTS FOR isValidDate() ---------
TEST(WorkoutLoggerTests, IsValidDate_ValidDates) {
    EXPECT_TRUE(isValidDate("2024-05-02"));
    EXPECT_TRUE(isValidDate("2025-12-31"));
}

TEST(WorkoutLoggerTests, IsValidDate_InvalidFormat) {
    EXPECT_FALSE(isValidDate("2025/12/31"));
    EXPECT_FALSE(isValidDate("20251231"));
    EXPECT_FALSE(isValidDate("20-12-2025"));
    EXPECT_FALSE(isValidDate("abcd-ef-gh"));
}

TEST(WorkoutLoggerTests, IsValidDate_InvalidValues) {
    EXPECT_FALSE(isValidDate("2026-01-01")); // future year
    EXPECT_FALSE(isValidDate("2025-13-01")); // invalid month
    EXPECT_FALSE(isValidDate("2025-00-10")); // invalid month
    EXPECT_FALSE(isValidDate("2025-10-32")); // invalid day
    EXPECT_FALSE(isValidDate("2025-02-00")); // invalid day
}

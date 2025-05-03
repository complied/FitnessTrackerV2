// test/full_test_suite.cpp
#include <gtest/gtest.h>
#include <memory>
#include <fstream>
#include <cstdio>   // for remove()
#include "../include/calorieChecker.h"
#include "../include/workoutLogger.h"
#include "../include/workoutAssign.h"
#include "../include/fileManager.h"

using namespace calorieChecker;
using namespace logWorkout;
using namespace workoutManager;

// --- Helper Function for Calories ---
double computeCalories(WorkoutType type, double weight, double duration) {
    if (type == WorkoutType::Running)
        return weight * 0.0175 * 9.8 * duration;
    if (type == WorkoutType::Swimming)
        return weight * 0.0175 * 7.0 * duration;
    return weight * 0.0175 * 8.0 * duration;
}

// ---------- CALORIE CHECKER TESTS ----------
TEST(ParseWorkoutTest, ValidInputs) {
    EXPECT_EQ(parseWorkout("Running"), WorkoutType::Running);
    EXPECT_EQ(parseWorkout("Swimming"), WorkoutType::Swimming);
    EXPECT_EQ(parseWorkout("Biking"), WorkoutType::Biking);
}

TEST(ParseWorkoutTest, InvalidInputDefaultsToBiking) {
    EXPECT_EQ(parseWorkout("Yoga"), WorkoutType::Biking);
}

TEST(CalorieCalculationTest, Running) {
    EXPECT_DOUBLE_EQ(computeCalories(WorkoutType::Running, 60, 30), 308.7);
}

TEST(CalorieCalculationTest, Swimming) {
    EXPECT_DOUBLE_EQ(computeCalories(WorkoutType::Swimming, 70, 45), 551.25);
}

TEST(CalorieCalculationTest, Biking) {
    EXPECT_DOUBLE_EQ(computeCalories(WorkoutType::Biking, 55, 40), 308.0);
}

TEST(SmartPointerTest, UniquePtrSession) {
    auto session = std::make_unique<CalorieSession>();
    session->type = WorkoutType::Running;
    session->weight = 65;
    session->duration = 20;
    session->calories = computeCalories(session->type, session->weight, session->duration);
    EXPECT_GT(session->calories, 0);
}

// ---------- WORKOUT LOGGER TESTS ----------
TEST(DateValidationTest, ValidDates) {
    EXPECT_TRUE(isValidDate("2025-04-28"));
    EXPECT_TRUE(isValidDate("2023-12-01"));
}

TEST(DateValidationTest, InvalidDates) {
    EXPECT_FALSE(isValidDate("2026-01-01"));
    EXPECT_FALSE(isValidDate("2025/01/01"));
    EXPECT_FALSE(isValidDate("abcd-ef-gh"));
    EXPECT_FALSE(isValidDate("2025-13-01"));
    EXPECT_FALSE(isValidDate("2025-01-32"));
}

// ---------- WORKOUT ASSIGNMENT MAP TESTS ----------
TEST(WorkoutAssignTest, LimitPerDay) {
    string testDay = "Monday";
    for (int i = 0; i < 5; i++) {
        shared_ptr<workout> w = make_shared<workout>("TestWorkout", 30);
        workoutManager[testDay].push_back(w);
    }
    EXPECT_EQ(workoutManager[testDay].size(), 5);
}

// ---------- FILE MANAGER TEST ----------
TEST(FileManagerTest, BinaryWriteAndRead) {
    // Create temp binary file and write a session
    const char* path = "test_temp_session.dat";
    fileManager::BinarySession s {"Running", 60.0, 30.0, computeCalories(WorkoutType::Running, 60, 30)};

    std::ofstream out(path, std::ios::binary);
    ASSERT_TRUE(out.is_open());
    out.write(reinterpret_cast<char*>(&s), sizeof(s));
    out.close();
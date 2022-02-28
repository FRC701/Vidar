// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <algorithm>

#include "../../test/cpp/TestVisionShoot.h"

using vision_shoot::VisionToSpeed;
using vision_shoot::FindSpeed;

TEST_F(TestVisionShoot, EmptyDataFails) {
    VisionToSpeed emptyVisionToSpeeds {};
    constexpr double kTestTargetArea = 0.1; // Use any target area for this test

    // How is an error identified? 
    // A good choice is to use an exception. However, in robot code an exception
    // can cause a crash. 
    // In this case, we'll use a special return value. 
    // A return vale of 0 for a speed will indicate that this data didn't return
    // anything useable.
    double speed = FindSpeed(&emptyVisionToSpeeds, &emptyVisionToSpeeds, kTestTargetArea);

    EXPECT_EQ(speed, 0.0);
}

TEST_F(TestVisionShoot, SingleValueFails) {
    // A single valued table is probably also not very useful for linear interpolation
    VisionToSpeed singleVisionToSpeeds[] {
        { 0, 1, 2}  // Any values as this test should fail
    };
    constexpr double kTestTargetArea = 0.1; // Use any target area for this test

    double speed 
        = FindSpeed(
            std::begin(singleVisionToSpeeds), 
            std::end(singleVisionToSpeeds), 
            kTestTargetArea);
    EXPECT_EQ(speed, 0.0);
}

// Build the simplest real test possible. 
// 1. Two values
// 2. Test for a value directly between the values
TEST_F(TestVisionShoot, SimpleInterpolation) {
    VisionToSpeed simpleVisionToSpeeds[] {
        { 30.0, 1.0, 300.0},
        { 10.0, 3.0, 100.0}
    };
    constexpr double kTestTargetArea = 2.0;
    // With this data the expected result for half way between the two values
    // would be half way between the speeds, so 200.0.

    // The value should probably be calculated, but this is good for this simple test.
    constexpr double kExpectedSpeed = 200.0;
    double speed 
        = FindSpeed(
            std::begin(simpleVisionToSpeeds), 
            std::end(simpleVisionToSpeeds), 
            kTestTargetArea);
    EXPECT_EQ(speed, kExpectedSpeed);
}

TEST_F(TestVisionShoot, largeInterpolation) {
    VisionToSpeed simpleVisionToSpeeds[] {
        { 10.0, 1.0, 100.0},
        { 20.0, 2.0, 200.0},
        { 30.0, 3.0, 300.0},
        { 40.0, 4.0, 400.0},
        { 50.0, 5.0, 500.0}
    };
    constexpr double kTestTargetArea = 1.5;
    // With this data the expected result for half way between two values
    // would be half way between the speeds, so 150.0.

    // The value should probably be calculated, but this is good for this simple test.
    constexpr double kExpectedSpeed = 150.0;
    double speed 
        = FindSpeed(
            std::begin(simpleVisionToSpeeds), 
            std::end(simpleVisionToSpeeds), 
            kTestTargetArea);
    EXPECT_EQ(speed, kExpectedSpeed);
}

TEST_F(TestVisionShoot, quarterInterpolation) {
    VisionToSpeed simpleVisionToSpeeds[] {
        { 10.0, 1.0, 100.0},
        { 20.0, 2.0, 200.0},
        { 30.0, 3.0, 300.0},
        { 40.0, 4.0, 400.0},
        { 50.0, 5.0, 500.0}
    };
    constexpr double kTestTargetArea = 1.25;
    // With this data the expected result for a quarter way between two values
    // would be quarter way between the speeds, so 125.0.

    // The value should probably be calculated, but this is good for this simple test.
    constexpr double kExpectedSpeed = 125.0;
    double speed 
        = FindSpeed(
            std::begin(simpleVisionToSpeeds), 
            std::end(simpleVisionToSpeeds), 
            kTestTargetArea);
    EXPECT_EQ(speed, kExpectedSpeed);
}

TEST_F(TestVisionShoot, threeQuarterInterpolation) {
    VisionToSpeed simpleVisionToSpeeds[] {
        { 10.0, 1.0, 100.0},
        { 20.0, 2.0, 200.0},
        { 30.0, 3.0, 300.0},
        { 40.0, 4.0, 400.0},
        { 50.0, 5.0, 500.0}
    };
    constexpr double kTestTargetArea = 3.75;
    // With this data the expected result for 3/4 way between two values
    // would be half way between the speeds, so 375.0.

    // The value should probably be calculated, but this is good for this simple test.
    constexpr double kExpectedSpeed = 375.0;
    double speed 
        = FindSpeed(
            std::begin(simpleVisionToSpeeds), 
            std::end(simpleVisionToSpeeds), 
            kTestTargetArea);
    EXPECT_EQ(speed, kExpectedSpeed);
}

TEST_F(TestVisionShoot, nonLinearInterpolation) {
    VisionToSpeed simpleVisionToSpeeds[] {
        { 10.0, 1.0,  5000.0},
        { 20.0, 5.0,  3500.0},
        { 30.0, 35.0, 2200.0},
        { 40.0, 45.0, 1400.0},
        { 50.0, 75.0, 500.0}
    };
    constexpr double kTestTargetArea = 42.5;

    constexpr double kExpectedSpeed = 1600.0;
    double speed 
        = FindSpeed(
            std::begin(simpleVisionToSpeeds), 
            std::end(simpleVisionToSpeeds), 
            kTestTargetArea);
    EXPECT_EQ(speed, kExpectedSpeed);
}

TEST_F(TestVisionShoot, exactTargetArea) {
    VisionToSpeed simpleVisionToSpeeds[] {
        { 10.0, 1.0,  5000.0},
        { 20.0, 5.0,  3500.0},
        { 30.0, 35.0, 2200.0},
        { 40.0, 45.0, 1400.0},
        { 50.0, 75.0, 500.0}
    };
    constexpr double kTestTargetArea = 45.0;

    constexpr double kExpectedSpeed = 1400.0;
    double speed 
        = FindSpeed(
            std::begin(simpleVisionToSpeeds), 
            std::end(simpleVisionToSpeeds), 
            kTestTargetArea);
    EXPECT_EQ(speed, kExpectedSpeed);
}

TEST_F(TestVisionShoot, lessThanTargetArea) {
    VisionToSpeed simpleVisionToSpeeds[] {
        { 10.0, 1.0,  5000.0},
        { 20.0, 5.0,  3500.0},
        { 30.0, 35.0, 2200.0},
        { 40.0, 45.0, 1400.0},
        { 50.0, 75.0, 500.0}
    };
    constexpr double kTestTargetArea = 0.1;

    constexpr double kExpectedSpeed = 0.0;
    double speed 
        = FindSpeed(
            std::begin(simpleVisionToSpeeds), 
            std::end(simpleVisionToSpeeds), 
            kTestTargetArea);
    EXPECT_EQ(speed, kExpectedSpeed);
}

TEST_F(TestVisionShoot, greaterThanTargetArea) {
    VisionToSpeed simpleVisionToSpeeds[] {
        { 10.0, 1.0,  5000.0},
        { 20.0, 5.0,  3500.0},
        { 30.0, 35.0, 2200.0},
        { 40.0, 45.0, 1400.0},
        { 50.0, 75.0, 500.0}
    };
    constexpr double kTestTargetArea = 85.0;

    constexpr double kExpectedSpeed = 0.0;
    double speed 
        = FindSpeed(
            std::begin(simpleVisionToSpeeds), 
            std::end(simpleVisionToSpeeds), 
            kTestTargetArea);
    EXPECT_EQ(speed, kExpectedSpeed);
}

TEST_F(TestVisionShoot, exactlyLastTargetArea) {
    VisionToSpeed simpleVisionToSpeeds[] {
        { 10.0, 1.0,  5000.0},
        { 20.0, 5.0,  3500.0},
        { 30.0, 35.0, 2200.0},
        { 40.0, 45.0, 1400.0},
        { 50.0, 75.0, 500.0}
    };
    constexpr double kTestTargetArea = 75.0;

    constexpr double kExpectedSpeed = 500.0;
    double speed 
        = FindSpeed(
            std::begin(simpleVisionToSpeeds), 
            std::end(simpleVisionToSpeeds), 
            kTestTargetArea);
    EXPECT_EQ(speed, kExpectedSpeed);
}


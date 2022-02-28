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


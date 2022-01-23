// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Feeder.h"

Feeder::Feeder(WPI_TalonFX& feederLeft, WPI_TalonFX& feederRight)
: mFeederLeft(feederLeft)
, mFeederRight(feederRight)
{
mFeederRight.Set(ControlMode::Follower, mFeederLeft.GetDeviceID());
}

// This method will be called once per scheduler run
void Feeder::Periodic() {}

double Feeder::FeederSpin(double speed)
{
    mFeederLeft.Set(speed);
    return speed;
}
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Feeder.h"

Feeder::Feeder(WPI_TalonFX& FeederLeft, WPI_TalonFX& FeederRight)
: FeederLeft(FeederLeft)
, FeederRight(FeederRight)
{}

// This method will be called once per scheduler run
void Feeder::Periodic() {}

double Feeder::FeederSpin(double speed)
{
    FeederLeft.Set(speed);
    FeederRight.Set(speed);
    return speed;
}
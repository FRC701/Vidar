// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Feeder.h"
#include <frc/smartdashboard/SmartDashboard.h>

Feeder::Feeder(WPI_TalonFX& feederBottom)
: mFeederBottom(feederBottom)
{
    mFeederBottom.OverrideLimitSwitchesEnable(false);
}

// This method will be called once per scheduler run
void Feeder::Periodic() 
{
  frc::SmartDashboard::PutBoolean("Ball Entering Feeder", BallIsComing());
  frc::SmartDashboard::PutBoolean("Ball Exiting Feeder", BallIsExiting());
}
 
bool Feeder::BallIsComing()
{
    return !mFeederBottom.IsRevLimitSwitchClosed();
}
bool Feeder::BallIsExiting()
{
    return !mFeederBottom.IsFwdLimitSwitchClosed();
}

double Feeder::FeederSpin(double speed)
{
    mFeederBottom.Set(speed);
    return speed;
}
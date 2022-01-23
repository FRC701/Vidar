// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Feeder.h"

Feeder::Feeder(WPI_TalonFX& feederBottom, WPI_TalonFX& feederTop)
: FeederBottom(feederBottom)
, FeederTop(feederTop)
{
    FeederTop.Set(ControlMode::Follower, FeederBottom.GetDeviceID());
}

// This method will be called once per scheduler run
void Feeder::Periodic() 
{
  frc::SmartDashboard::PutBoolean("Ball Entering Feeder", BallIsComing());
  frc::SmartDashboard::PutBoolean("Ball Exiting Feeder", BallIsExiting());
}
 
bool Feeder::BallIsComing()
{
    return FeederBottom.IsRevLimitSwitchClosed();
}
bool Feeder::BallIsExiting()
{
    return FeederTop.IsRevLimitSwitchClosed();
}


double Feeder::FeederSpin(double speed)
{
    FeederBottom.Set(speed);
    return speed;
}
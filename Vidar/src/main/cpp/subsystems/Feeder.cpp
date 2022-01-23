// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.
#include <frc/smartdashboard/SmartDashboard.h>
#include "subsystems/Feeder.h"

Feeder::Feeder(WPI_TalonFX& FeederBottom, WPI_TalonFX& FeederTop)
: FeederBottom(FeederBottom)
, FeederTop(FeederTop)
{}

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
    FeederTop.Set(speed);
    return speed;
}

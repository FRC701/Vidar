// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Shooter.h"

Shooter::Shooter(WPI_TalonFX& flywheelMotor1, WPI_TalonFX& flywheelMotor2) 
: mFlywheelMotor1(flywheelMotor1)
, mFlywheelMotor2(flywheelMotor2)
{
    mFlywheelMotor1.Set(ControlMode::Follower, mFlywheelMotor2.GetDeviceID());
}

double Shooter::SpinFlywheel(double speed)
{
    mFlywheelMotor1.Set(speed);
    mFlywheelMotor2.Set(speed);
    return speed;
}

// This method will be called once per scheduler run
void Shooter::Periodic() {}

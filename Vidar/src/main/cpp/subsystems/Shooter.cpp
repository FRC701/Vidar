// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Shooter.h"

Shooter::Shooter(WPI_TalonFX& FlywheelMotor, WPI_TalonFX& HoodMotor) 
: FlywheelMotor(FlywheelMotor)
, HoodMotor(HoodMotor)
{}

double Shooter::SpinFlywheel(double speed)
{
    FlywheelMotor.Set(speed);
    return speed;
}

void Shooter::MoveHood(double speed)
{
    HoodMotor.Set(speed);
}
// This method will be called once per scheduler run
void Shooter::Periodic() {}

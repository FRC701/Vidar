// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Shooter.h"
#include "frc/smartdashboard/SmartDashboard.h"

Shooter::Shooter(WPI_TalonFX& flywheelMotor1, WPI_TalonFX& flywheelMotor2) 
: mFlywheelMotor1(flywheelMotor1)
, mFlywheelMotor2(flywheelMotor2)
{
    constexpr auto kMotor1IsInverted {false};
    mFlywheelMotor1.SetInverted(kMotor1IsInverted);
    mFlywheelMotor2.SetInverted(!kMotor1IsInverted);
    mFlywheelMotor2.Set(ControlMode::Follower, mFlywheelMotor1.GetDeviceID());
}

double Shooter::SpinFlywheel(double speed)
{
    mFlywheelMotor1.Set(speed);
    return speed;
}

bool Shooter::IsReadyToShoot()
{
    return true;
}

double Shooter::FlywheelVelocity() 
{
  return mFlywheelMotor1.GetSelectedSensorVelocity();
}

// This method will be called once per scheduler run
void Shooter::Periodic() 
{
    frc::SmartDashboard::PutNumber("Flywheel Velocity", FlywheelVelocity());
}

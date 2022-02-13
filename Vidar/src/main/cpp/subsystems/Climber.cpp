// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Climber.h"
#include "ctre/phoenix/music/Orchestra.h"

Climber::Climber(WPI_TalonFX& InsideMotorLeft, WPI_TalonFX& InsideMotorRight, WPI_TalonFX& OutsideMotorLeft, WPI_TalonFX& OutsideMotorRight)
: InsideMotorLeft(InsideMotorLeft)
, InsideMotorRight(InsideMotorRight)
, OutsideMotorLeft(OutsideMotorLeft)
, OutsideMotorRight(OutsideMotorRight)
{}
// This method will be called once per scheduler run
void Climber::Periodic() {}
 
double Climber::Inside(double speed)
{
    InsideMotorLeft.Set(speed);
    InsideMotorRight.Set(speed);
    return speed;
}

double Climber::Outside(double speed) 
{
    OutsideMotorLeft.Set(speed);
    OutsideMotorRight.Set(speed);
    return speed;
}


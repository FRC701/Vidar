// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/FlywheelShoot.h"

FlywheelShoot::FlywheelShoot(Shooter& shooter, double motorspeed) 
: mShooter(shooter)
, motorspeed(motorspeed)
{
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void FlywheelShoot::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void FlywheelShoot::Execute() 
{
mShooter.SpinFlywheel(motorspeed);
}

// Called once the command ends or is interrupted.
void FlywheelShoot::End(bool interrupted) 
{
  mShooter.SpinFlywheel(0.0);
}

// Returns true when the command should end.
bool FlywheelShoot::IsFinished() {
  return false;
}

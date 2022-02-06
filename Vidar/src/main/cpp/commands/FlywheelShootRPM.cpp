// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/FlywheelShootRPM.h"

FlywheelShootRPM::FlywheelShootRPM(Shooter& shooter, double Speedrpm)
:mShooter(shooter)
,speedrpm(Speedrpm)
{
  AddRequirements(&mShooter);
}

// Called when the command is initially scheduled.
void FlywheelShootRPM::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void FlywheelShootRPM::Execute() 
{
  mShooter.SpinFlywheelRPM(speedrpm); 
}

// Called once the command ends or is interrupted.
void FlywheelShootRPM::End(bool interrupted) 
{
  mShooter.SpinFlywheelRPM(0);
}

// Returns true when the command should end.
bool FlywheelShootRPM::IsFinished() {
  return false;
}

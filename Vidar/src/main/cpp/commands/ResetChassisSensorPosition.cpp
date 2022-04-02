// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ResetChassisSensorPosition.h"

ResetChassisSensorPosition::ResetChassisSensorPosition(Chassis& chassis) 
:mChassis(chassis)
{
  AddRequirements(&mChassis);
}

// Called when the command is initially scheduled.
void ResetChassisSensorPosition::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ResetChassisSensorPosition::Execute() 
{
  mChassis.ResetRightPos();
  mChassis.ResetLeftPos();
}

// Called once the command ends or is interrupted.
void ResetChassisSensorPosition::End(bool interrupted) {}

// Returns true when the command should end.
bool ResetChassisSensorPosition::IsFinished() {
  return false;
}

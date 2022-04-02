// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AutoTankDriveSpin360.h"

AutoTankDriveSpin360::AutoTankDriveSpin360(Chassis& chassis)
: mChassis(chassis)
{
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void AutoTankDriveSpin360::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void AutoTankDriveSpin360::Execute() {}

// Called once the command ends or is interrupted.
void AutoTankDriveSpin360::End(bool interrupted) {}

// Returns true when the command should end.
bool AutoTankDriveSpin360::IsFinished() {
  return false;
}

// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/TimeDriveTurn.h"

TimeDriveTurn::TimeDriveTurn() {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void TimeDriveTurn::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void TimeDriveTurn::Execute() {}

// Called once the command ends or is interrupted.
void TimeDriveTurn::End(bool interrupted) {}

// Returns true when the command should end.
bool TimeDriveTurn::IsFinished() {
  return false;
}

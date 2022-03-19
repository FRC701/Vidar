// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/TRleft.h"

TRleft::TRleft(Climber& climber, double Motorspeed) 
: mClimber(climber)
, motorspeed(Motorspeed)
{
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void TRleft::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void TRleft::Execute() 
{
  mClimber.TRleft(motorspeed);
}

// Called once the command ends or is interrupted.
void TRleft::End(bool interrupted) {}

// Returns true when the command should end.
bool TRleft::IsFinished() {
  return false;
}

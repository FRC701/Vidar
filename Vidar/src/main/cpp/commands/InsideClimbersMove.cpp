// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/InsideClimbersMove.h"

InsideClimbersMove::InsideClimbersMove(Climber& climber, double motorspeed)
:mClimber(climber)
,motorspeed(motorspeed)
{
  AddRequirements(&mClimber);
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void InsideClimbersMove::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void InsideClimbersMove::Execute() 
{
  mClimber.Inside(motorspeed);
}

// Called once the command ends or is interrupted.
void InsideClimbersMove::End(bool interrupted) 
{
  mClimber.Inside(0);
}

// Returns true when the command should end.
bool InsideClimbersMove::IsFinished() {
  return false;
}

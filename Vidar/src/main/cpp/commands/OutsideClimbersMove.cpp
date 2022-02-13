// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/OutsideClimbersMove.h"

OutsideClimbersMove::OutsideClimbersMove(Climber& climber, std::function<double()> touchdownHooks)
:mClimber(climber)
,mTouchdownHooks(touchdownHooks)
{
  AddRequirements(&mClimber);
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void OutsideClimbersMove::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void OutsideClimbersMove::Execute() 
{
  mClimber.Outside(mTouchdownHooks());
}

// Called once the command ends or is interrupted.
void OutsideClimbersMove::End(bool interrupted) 
{
  mClimber.Outside(0);
}

// Returns true when the command should end.
bool OutsideClimbersMove::IsFinished() {
  return false;
}

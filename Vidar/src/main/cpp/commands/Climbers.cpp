// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Climbers.h"

Climbers::Climbers(Climber& climber, std::function<double()> touchdownHooks, std::function<double()> tuskanRaiderHooks)
: mClimber(climber)
, mTouchdownHooks(touchdownHooks)
, mTuskanRaiderHooks(tuskanRaiderHooks)
{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(&mClimber);
}

// Called when the command is initially scheduled.
void Climbers::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void Climbers::Execute() 
{

if(mClimber.TouchdownFwd() && mTouchdownHooks() > 0.0)
{
  mClimber.Inside(0.0);
}

if(mClimber.TouchdownRev() && mTouchdownHooks() < 0.0)
{
  mClimber.Inside(0.0);
}

 mClimber.Inside(mTouchdownHooks());

if(mClimber.RightClimberIsDown() && mTuskanRaiderHooks() > 0.0)
  {
    mClimber.Inside(0.00);
  }
    mClimber.Outside(mTuskanRaiderHooks());

if(mClimber.LeftClimberIsDown() && mTouchdownHooks() > 0.0)
  {
    mClimber.Inside(0.00);
  }
    mClimber.Outside(mTuskanRaiderHooks());
}

// Called once the command ends or is interrupted.
void Climbers::End(bool interrupted) 
{
  mClimber.Outside(0);
  mClimber.Inside(0);
}

// Returns true when the command should end.
bool Climbers::IsFinished() {
  return false;
}

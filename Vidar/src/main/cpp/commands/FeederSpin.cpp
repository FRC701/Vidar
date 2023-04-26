// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/FeederSpin.h"



FeederSpin::FeederSpin(Feeder& mFeeder, double motorspeed) 
:mFeeder(mFeeder), mMotorSpeed(motorspeed)
{
  AddRequirements(&mFeeder);
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void FeederSpin::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void FeederSpin::Execute() 
{
  mFeeder.FeederSpin(mMotorSpeed);
}

// Called once the command ends or is interrupted.
void FeederSpin::End(bool interrupted) {
  mFeeder.FeederSpin(0.0);
}

// Returns true when the command should end.
bool FeederSpin::IsFinished() {
  return false;
}

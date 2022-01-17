// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/SpinFeeder.h"

SpinFeeder::SpinFeeder(Feeder& feeder, double motorspeed)
: mFeeder(feeder)
, motorspeed(motorspeed)

{
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void SpinFeeder::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void SpinFeeder::Execute()
{
 mFeeder.FeederSpin(motorspeed);
}

// Called once the command ends or is interrupted.
void SpinFeeder::End(bool interrupted) 
{
  mFeeder.FeederSpin(0);
}

// Returns true when the command should end.
bool SpinFeeder::IsFinished() {
  return false;
}

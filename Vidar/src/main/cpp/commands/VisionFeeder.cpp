// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/VisionFeeder.h"

VisionFeeder::VisionFeeder(Feeder& feeder, double motorspeed) 
: mFeeder(feeder)
, motorspeed(motorspeed)
{
  AddRequirements(&mFeeder);
}

// Called when the command is initially scheduled.
void VisionFeeder::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void VisionFeeder::Execute() 
{
  mFeeder.FeederSpin(motorspeed);
}

// Called once the command ends or is interrupted.
void VisionFeeder::End(bool interrupted) 
{
  mFeeder.FeederSpin(motorspeed);
}

// Returns true when the command should end.
bool VisionFeeder::IsFinished() {
  return false;
}

// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ShootFeeder.h"

ShootFeeder::ShootFeeder(Feeder& mFeeder, double motorspeed) 
: mFeeder(mFeeder)
, motorspeed(motorspeed)
{
  // Use addRequirements() here to declare subsystem dependencies.

}

// Called when the command is initially scheduled.

void ShootFeeder::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ShootFeeder::Execute() 
{
  if (mFeeder.BallIsExiting())
 {
   motorspeed = 0;
 }
 mFeeder.FeederSpin(motorspeed);
}

// Called once the command ends or is interrupted.
void ShootFeeder::End(bool interrupted) {}

// Returns true when the command should end.
bool ShootFeeder::IsFinished() {
  return false;
}

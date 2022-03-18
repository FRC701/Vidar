// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/TimedSpinFeeder.h"

TimedSpinFeeder::TimedSpinFeeder(double Motorspeed, Feeder& feeder, units::second_t timeout)
: motorspeed(Motorspeed)
, mFeeder(feeder)
, mTimeout(timeout)
{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(&mFeeder);
}

// Called when the command is initially scheduled.
void TimedSpinFeeder::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void TimedSpinFeeder::Execute() 
{
  mTimer.Start();
  if(mTimer.HasElapsed(units::second_t(0.25)))
  {
  mFeeder.FeederSpin(motorspeed);
  }
}

// Called once the command ends or is interrupted.
void TimedSpinFeeder::End(bool interrupted)
{
  mTimer.Reset();
}

// Returns true when the command should end.
bool TimedSpinFeeder::IsFinished() {
  return mTimer.HasElapsed(mTimeout);
}

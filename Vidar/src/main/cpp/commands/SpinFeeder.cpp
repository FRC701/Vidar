// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/SpinFeeder.h"


SpinFeeder::SpinFeeder(Feeder& feeder, double motorspeed)
: mFeeder(feeder)
, mMotorspeed(motorspeed)
, mDebounceCount(0)
{
  AddRequirements(&mFeeder);
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void SpinFeeder::Initialize() {
  mDebounceCount = 0;
}

// Called repeatedly when this Command is scheduled to run
void SpinFeeder::Execute()
{
  // 20ms per cycle
  constexpr int kDebounceCount = 10; // TODO Do math for ms to count
  double speed = 0.0;

  if (mFeeder.BallIsComing())
  {
    if (mDebounceCount > kDebounceCount) {
      speed = mMotorspeed;
    }
    else {
      ++mDebounceCount;
    }
  }
  else {
    mDebounceCount = 0;
  }

  //Exit Check MUST BE LAST in order to overide Enter Check. 
  if (mFeeder.BallIsExiting())
  {
    speed = 0.0;
  }

  mFeeder.FeederSpin(speed);
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

// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <frc/smartdashboard/SmartDashboard.h>
#include "commands/FeederShoot.h"

FeederShoot::FeederShoot(Feeder& feeder, Shooter& shooter, double Feederspeed)
: mFeeder(feeder)
, mShooter(shooter)
, feederspeed(Feederspeed)
{
  AddRequirements(&mFeeder);
}

// Called when the command is initially scheduled.
void FeederShoot::Initialize() {
  mState = CommandState_WaitingForBall;
}

// Called repeatedly when this Command is scheduled to run
void FeederShoot::Execute() {

  frc::SmartDashboard::PutNumber("Current Case", mState);

  switch (mState)
  {
    case CommandState_WaitingForBall:
      WaitingForBall();
      break;
    case CommandState_WaitingForShooter:
      WaitingForShooter();
      break;
    case CommandState_Shooting:
      Shooting();
      break;
  }
}

// The feeder is waiting for a ball. 
// Change to WairingForShooter when a ball is found.
void FeederShoot::WaitingForBall()
{
  if(mFeeder.BallIsExiting())
  {
    mState = CommandState_WaitingForShooter;
  }
  else
  {
  mFeeder.FeederSpin(feederspeed);
  }
}

// The feeder is waiting for the shooter to be ready to shoot. 
// Change to shooting when the shooter is ready.
void FeederShoot::WaitingForShooter()
{
  if(mShooter.IsReadyToShoot())
  {
    mState = CommandState_Shooting;
  }
  else
  {
  mFeeder.FeederSpin(0);
  }
}

// The feeder is shooting a ball. 
// Switch to Waiting for a ball when the ball goes out.
void FeederShoot::Shooting()
{
  mFeeder.FeederSpin(feederspeed);

  if(!mFeeder.BallIsExiting())
  {
   mState = CommandState_WaitingForBall;
  }

}

// Called once the command ends or is interrupted.
void FeederShoot::End(bool interrupted) {}

// Returns true when the command should end.
bool FeederShoot::IsFinished() {
  return false;
}

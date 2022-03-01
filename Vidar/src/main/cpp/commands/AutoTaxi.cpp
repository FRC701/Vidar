// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AutoTaxi.h"

AutoTaxi::AutoTaxi(Chassis& chassis, units::second_t chassisTimeout, double chassisDrive, double leftChassis, double rightChassis) 
: mChassis(chassis)
, mChassisTimeout(chassisTimeout)
, mChassisDrive(chassisDrive)
, mleftChassis(leftChassis)
, mrightChassis(rightChassis)
{
  AddRequirements(&mChassis);
}

// Called when the command is initially scheduled.
void AutoTaxi::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void AutoTaxi::Execute() 
{
  mTimer.Start();
  mChassis.TankDrive(mChassisDrive, mChassisDrive);
  if(mTimer.HasElapsed(units::second_t(3)))
  {
    mChassis.TankDrive(mleftChassis, mrightChassis);
  }
}

// Called once the command ends or is interrupted.
void AutoTaxi::End(bool interrupted) {}

// Returns true when the command should end.
bool AutoTaxi::IsFinished() {
  return mTimer.HasElapsed(mChassisTimeout);
}

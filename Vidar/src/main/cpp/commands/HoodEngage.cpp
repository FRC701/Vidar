// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/HoodEngage.h"

HoodEngage::HoodEngage(Shooter& shooter, double hoodspeed) 
: mShooter(shooter)
, mHoodspeed(hoodspeed)

{
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void HoodEngage::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void HoodEngage::Execute()
 {
   mShooter.MoveHood(mHoodspeed);
 }

// Called once the command ends or is interrupted.
void HoodEngage::End(bool interrupted) 
{
  mShooter.MoveHood(0.0);
}

// Returns true when the command should end.
bool HoodEngage::IsFinished() {
  return false;
}

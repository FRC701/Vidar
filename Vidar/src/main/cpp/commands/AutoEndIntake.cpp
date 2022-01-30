// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AutoEndIntake.h"

AutoEndIntake::AutoEndIntake(Intake& mIntake, Feeder& mFeeder)
: mIntake(mIntake)
, mFeeder(mFeeder)
 {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(&mIntake);
}

// Called when the command is initially scheduled.
void AutoEndIntake::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void AutoEndIntake::Execute() 
{
if (mFeeder.BallIsExiting()) 
{
  mIntake.IntakeSpin(0);
  mIntake.IntakeDisengage();
}
}

// Called once the command ends or is interrupted.
void AutoEndIntake::End(bool interrupted) {}

// Returns true when the command should end.
bool AutoEndIntake::IsFinished() {
  return false;
}

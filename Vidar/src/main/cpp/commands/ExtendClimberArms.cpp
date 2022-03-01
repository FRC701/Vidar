// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ExtendClimberArms.h"

ExtendClimberArms::ExtendClimberArms(Climber& climber)
:mClimber(climber)
{
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void ExtendClimberArms::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ExtendClimberArms::Execute() 
{
  mClimber.ExtendArms();
}

// Called once the command ends or is interrupted.
void ExtendClimberArms::End(bool interrupted) 
{
  mClimber.RetractArms();
}

// Returns true when the command should end.
bool ExtendClimberArms::IsFinished() {
  return false;
}

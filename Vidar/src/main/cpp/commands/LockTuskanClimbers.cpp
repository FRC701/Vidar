// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/LockTuskanClimbers.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
LockTuskanClimbers::LockTuskanClimbers(Climber& climber) 
:mClimber(climber)
{
  AddRequirements(&mClimber);// Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void LockTuskanClimbers::Initialize() 
{
  mClimber.ExtendArms();
}

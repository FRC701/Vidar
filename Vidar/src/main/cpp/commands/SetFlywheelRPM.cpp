// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/SetFlywheelRPM.h"
#include "frc/smartdashboard/SmartDashboard.h"

SetFlywheelRPM::SetFlywheelRPM(Shooter& shooter)
:mShooter(shooter)
{
    AddRequirements(&mShooter);
}

// Called when the command is initially scheduled.
void SetFlywheelRPM::Initialize() {
  mShooter.ResetVelocity();
}

// Called repeatedly when this Command is scheduled to run
void SetFlywheelRPM::Execute() 
{
  double velocity = frc::SmartDashboard::GetNumber("Set Flywheel VelocityRPM", 0);
  mShooter.SpinFlywheelRPM(velocity);  
}

// Called once the command ends or is interrupted.
void SetFlywheelRPM::End(bool interrupted) {}

// Returns true when the command should end.
bool SetFlywheelRPM::IsFinished() {
  return false;
}

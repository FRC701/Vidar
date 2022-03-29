// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/VisionAim2.h"

namespace
{
  double position = 0;
}
VisionAim2::VisionAim2(Chassis& chassis)
: mChassis(chassis)
{
  AddRequirements(&mChassis);
}

// Called when the command is initially scheduled.
void VisionAim2::Initialize() 
{
  controller.SetTolerance(2);
}

// Called repeatedly when this Command is scheduled to run
void VisionAim2::Execute() 
{
  double output = controller.Calculate(mChassis.TargetOffset(), 0.0);
  mChassis.ArcadeDrive(0, position - output);
}

// Called once the command ends or is interrupted.
void VisionAim2::End(bool interrupted) 
{}

// Returns true when the command should end.
bool VisionAim2::IsFinished() {
  return controller.AtSetpoint();
}

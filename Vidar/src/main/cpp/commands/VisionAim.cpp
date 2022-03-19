// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/VisionAim.h"

// The implementation is inspired by the 
// [Case Study: Aiming Using Vision](https://docs.limelightvision.io/en/latest/cs_aiming.html) 
// article
  

namespace {

double kP = 0.05;  // Adjust kP first
double kI = 0.0;  // Keep 0. 
double kD = 0.0;  // Keep 0.
double kF = 0;  // Adjust to get out of the deadband

}


// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
VisionAim::VisionAim(Chassis& chassis)
    : CommandHelper(
          frc2::PIDController(kP, kI, kD),
          // This should return the measurement
          [this] { return mChassis.TargetOffset(); },
          // This should return the setpoint (can also be a constant)
          [this] { return 0.0; },
          // This uses the output
          [this](double output) {
            // Use the output here
            // Left turn is negative, right turn is positive
            // TODO Is this backward?
            mChassis.ArcadeDrive(0, kF - output);
          })
    , mChassis(chassis) {
    GetController().SetTolerance(2); // TODO Should the tolerance be opened?

    AddRequirements(&mChassis);
  }
  
void VisionAim::Initialize() {
  mChassis.limeLightLightsOn();
  super::Initialize();
}

// Returns true when the command should end.
bool VisionAim::IsFinished() {
  return GetController().AtSetpoint();
}
